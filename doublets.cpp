#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include "graph.h"

using namespace std;

graph<string> g;
set<string> s; //knuth dictionary

int matches(string word1, string word2) {
    int m = 0;
    //count # of matching characters in strings of length 5
    for(int i = 0; i < 5; i++) {
        if (word1[i] == word2[i]) {
            m++;
        }
    }
    return m;
}

void setUp(){
  ifstream in("knuth.txt");
  string word;

  while(getline(in,word)){
      g.add_vertex(word);
      s.insert(word);
  }
  in.close();

  int i = 0;
  int j = 0;
  for(string word1 : s){
    for(string word2 : s){
      if(matches(word1, word2) == 4){
        g.add_edge(i, j);
      }
      j++;
    }
    i++;
  }
}

void solve(string first, string last){
  size_t idx1, idx2;

  int i = 0;
  for(string w : s){
    if(first == w){
      idx1 = i; //index of first word
    }
    i++;
  }

  int j = 0;
  for(string w : s){
    if(last == w){
      idx2 = j; //index of last word
    }
    j++;
  }

  vector <size_t> word = g.shortest_path(idx1, idx2);
  for(auto it = word.begin(); it != word.end(); it++){
    //find index in s
    int index = 0;
    for(string find : s){
      if(index == *it){
        cout << find << " ";
      }
      index++;
    }
  }
  cout << endl;

}


int main(){

  setUp();

  solve("black", "white");
  solve("tears", "smile");
  solve("small", "giant");
  solve("stone", "money");
  solve("angel", "devil");
  solve("amino", "right");
  solve("amigo", "signs");


  return 0;
}
