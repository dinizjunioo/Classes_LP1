#include "StrTokenizer.h"
//
StrTokenizer::StrTokenizer(void)
{

}
//
StrTokenizer::StrTokenizer(std::string name, char delim)
{
    m_curr_idx = 0;
    m_delimiter = delim;
    m_input = input;
}
//
void StrTokenizer::prev(size_t ini)
{
 // verifica se o salto vai ultrapssar o limite de tokens
    if(m_curr_idx+step <= m_tokens.size())
        m_curr_idx = m_tokens.size();
    else
        m_curr_idx-=std;
}
//
void StrTokenizer::next(size_t ini)
{
    // verifica se o salto vai ultrapssar o limite de tokens
    if(m_curr_idx+step >= m_tokens.size())
        m_curr_idx = m_tokens.size();
    else
        m_curr_idx+=std;
}
//
void std::string StrTokenizer::get_token()
{

}
//
void StrTokenizer::set_input(string name)
{

}
void StrTokenizer::tokenize(void)
{

}