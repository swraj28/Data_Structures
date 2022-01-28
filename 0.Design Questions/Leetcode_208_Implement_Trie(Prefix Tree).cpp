#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

class node {
public:
	char ch;
	unordered_map<char, node*> h;
	bool isTerminal;

	node(char ch) {
		this->ch = ch;
		this->isTerminal = false;
	}
};

class Trie {
	node* root;
public:
	Trie() {
		root = new node('\0');
	}

	void insert(string word) {

		node* temp = root;

		for (int i = 0; i < word.length(); i++) {

			char ch = word[i];

			if (temp->h.count(ch)) {
				temp = temp->h[ch];
			} else {
				node* child = new node(ch);
				temp->h[ch] = child;
				temp = temp->h[ch];
			}
		}

		temp->isTerminal = true;
	}

	bool search(string word) {

		node* temp = root;

		for (int i = 0; i < word.length(); i++) {

			char ch = word[i];

			if (temp->h.count(ch)) {
				temp = temp->h[ch];
			} else {
				return false;
			}

		}

		return temp->isTerminal;
	}

	bool startsWith(string prefix) {

		node* temp = root;

		for (int i = 0; i < prefix.length(); i++) {

			char ch = prefix[i];

			if (temp->h.count(ch)) {
				temp = temp->h[ch];
			} else {
				return false;
			}
		}

		return true;
	}
};