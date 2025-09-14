bool isVowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string normalizeVowel(string s) {

    for (char &c : s) {
        c = tolower(c);
        if (isVowel(c))
             c = '*';
    }

    return s;
}

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isTerminal;
    string word; // store the first inserted original word

    TrieNode() {
        isTerminal = false;
        word = "";
    }

    void insert(TrieNode* root, string key, string original) {

        TrieNode* temp = root;
        for (char c : key) {

            if (!temp->children.count(c))
                temp->children[c] = new TrieNode();

            temp = temp->children[c];
        }

        if (!temp->isTerminal) { // only set on first insert
            temp->isTerminal = true;
            temp->word = original;
        }
    }

    string search(TrieNode* root, string key) {

        TrieNode* temp = root;
        for (char c : key) {
            if (!temp->children.count(c)) return "";
            temp = temp->children[c];
        }

        return temp->isTerminal ? temp->word : "";
    }
};

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

        TrieNode* exactRoot = new TrieNode();
        TrieNode* lowerRoot = new TrieNode();
        TrieNode* vowelRoot = new TrieNode();

        for (string w : wordlist) {
            exactRoot->insert(exactRoot, w, w);

            string lower = w;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            lowerRoot->insert(lowerRoot, lower, w);

            string vnorm = normalizeVowel(w);
            vowelRoot->insert(vowelRoot, vnorm, w);
        }

        vector<string> ans;
        for (string q : queries) {
            // 1. exact
            string curr = exactRoot->search(exactRoot, q);
            if (!curr.empty()) {
                ans.push_back(curr);
                continue;
            }

            // 2. lowercase
            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            curr = lowerRoot->search(lowerRoot, lower);
            if (!curr.empty()) {
                ans.push_back(curr);
                continue;
            }

            // 3. vowel normalized
            string vnorm = normalizeVowel(q);
            curr = vowelRoot->search(vowelRoot, vnorm);
            if (!curr.empty()) {
                ans.push_back(curr);
                continue;
            }

            ans.push_back("");
        }
        
        return ans;
    }
};
