class Solution
{
public:
    int calculate(string s)
    {
        stack<long long> st;

        long long result = 0;
        long long number = 0;
        int sign = 1;

        st.push(1);

        for (long long i = 0; i < s.length(); i++)
        {

            char c = s[i];

            if (isdigit(c))
            {
                number = number * 10 + (c - '0');
            }

            else if (c == '+')
            {
                result += sign * number;
                number = 0;
                sign = st.top();
            }

            else if (c == '-')
            {
                result += sign * number;
                number = 0;
                sign = -st.top();
            }

            else if (c == '(')
            {
                st.push(sign);
            }

            else if (c == ')')
            {
                result += sign * number;
                number = 0;
                st.pop();
                sign = st.top();
            }
        }

        result += sign * number;

        return result;
    }
};