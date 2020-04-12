class Solution {
public:
    string entityParser(string text) {
        vector<pair<string, string>> ps;
        ps.push_back({"&quot;", "\""});
        ps.push_back({"&apos;", "\'"});
        ps.push_back({"&amp;", "&"});
        ps.push_back({"&gt;", ">"});
        ps.push_back({"&lt;", "<"});
        ps.push_back({"&frasl;", "/"});

        string res;
        for(int i = 0; i < text.size(); i++) {
            if(text[i] == '&') {
                bool change = false;
                for(int j = 0; j < ps.size(); j++) {
                    int np = ps[j].first.size();
                    if(i + np - 1 >= text.size()) {
                        continue;
                    }
                    if(text.substr(i, np) == ps[j].first) {
                        res += ps[j].second;
                        i = i + np - 1;
                        change = true;
                        break;
                    }
                }
                if(!change) res += text[i];
            }
            else {
                res += text[i];
            }
        }
        return res;
    }
};

// Quotation Mark: the entity is &quot; and symbol character is ".
// Single Quote Mark: the entity is &apos; and symbol character is '.
// Ampersand: the entity is &amp; and symbol character is &.
// Greater Than Sign: the entity is &gt; and symbol character is >.
// Less Than Sign: the entity is &lt; and symbol character is <.
// Slash: the entity is &frasl; and symbol character is /.
