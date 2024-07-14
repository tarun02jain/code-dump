class Solution 
{
    struct Element
    {
        string el;
        int count;
    };
public:
    string countOfAtoms(string formula) {
        
        vector<Element> form{};
        
        auto num = 0;
        for (auto r = 0; r < std::size(formula); r++)
        {
            if (formula[r] == '(')
            {
                form.push_back({"(", 0});
            }
            else if (formula[r] == ')')
            {
                form.push_back({")", 0});
            }
            else if (isdigit(formula[r]))
            {
                auto num = formula[r] - '0';
                while (r+1 < std::size(formula) && isdigit(formula[r+1]))
                {
                    num = num*10+(formula[++r]-'0');
                }
                auto& prev = form.back();
                if (prev.count == 1)
                {
                    prev.count = 0;
                }
                form.back().count += num;
            }
            else if (isupper(formula[r]))
            {
                string element = {};
                element += formula[r];
                while (r+1 < std::size(formula) && islower(formula[r+1]))
                {
                    element += formula[++r];
                }
                form.push_back({element, 1});
            }
        }
        
        deque<int> open{};
        
        for (auto i = 0; i < std::size(form); i++)
        {
            if (form[i].el == "(")
            {
                open.push_back(i+1);
            }
            else if (form[i].el == ")")
            {
                if (form[i].count == 0)
                {
                    open.pop_back();
                    continue;
                }
                auto multiplier = form[i].count;
                auto start = open.back();
                open.pop_back();
                for(; start < i; start++)
                {
                    form[start].count*=multiplier;
                }
            }
        }
        
        map<string, int> elementCounts{};
        for (auto& element: form)
        {
            if (element.el != "(" && element.el != ")")
            {
                elementCounts[element.el] += element.count;
            }
        }
        string output = {};
        for (auto& [k, v] : elementCounts)
        {
            output += k;
            if (v > 1)
            {
                output += to_string(v);
            }
        }
        return output;
    }
};