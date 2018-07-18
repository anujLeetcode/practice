/*
535. Encode and Decode TinyURL
DescriptionHintsSubmissionsDiscussSolution
Pick One
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/
class Solution {
public:
	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string code;
		if (!url_code.count(longUrl)) {
			for (int i = 0; i < 6; i++)
				code.push_back(charset[rd() % charset.size()]);
			url_code.insert(pair<string, string>(longUrl, code));
			code_url.insert(pair<string, string>(code, longUrl));
		} else
			code = url_code[longUrl];
		return "http://tinyurl.com/" + code;
	}
	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		if (shortUrl.size() != 25 || !code_url.count(shortUrl.substr(19, 6)))
			return "";
		return code_url[shortUrl.substr(19, 6)];
	}
private:
	const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	map<string, string> url_code, code_url;
	random_device rd;
};
