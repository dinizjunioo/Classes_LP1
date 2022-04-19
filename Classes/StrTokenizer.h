#ifndef STR_TOKENIZER
#define STR_TOKENIZER
#include <string>
using std::string;

#include<vector>
using std::vector;

class StrTokenizer{
    private:
        string m_input;
        vector<string> m_tokens;
        char m_delimiter;
        size_t m_curr_idx; // using long 
    public:
        StrTokenizer();     //construtor
        StrTokenizer(string name, char delim); 
        void next(size_t step=1);
        void prev(size_t step=1);
        string get_token(void) const; // metodo de consulta, ele nao muda nada, por isso o const
        void set_delimiter(char new_delimiter);
        void set_input(string name);
        void tokenize(void);

};
#endif