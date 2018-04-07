/*
187. Repeated DNA Sequences
DescriptionHintsSubmissionsDiscussSolution
Pick One
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
int str2int(string s) {
    int str=0;
    for (int i = 0; i < s.size(); ++i)
        str = (str<<3) +(s[i]&7);
    return str;
}
vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    unordered_map<int,int> coll;
    for (int i = 0; i+10 <= s.size(); ++i)
        if (coll[str2int(s.substr(i,10))]++ == 1)
            res.push_back(s.substr(i,10));
    return res;
}
