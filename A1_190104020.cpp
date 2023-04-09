#include<bits/stdc++.h>
#define pb push_back
#define deb(x) cout<<#x<<"="<<x<<endl
using namespace std;
typedef long long int ll;
ifstream FileName;
fstream File2;
vector<string> keywords2,operators2,parenthesis2,separators2;
vector<string> SideCommentRemove1(vector<string> &vs)
{
    vector<string> ans;
    for(ll i=0; i<vs.size(); i++)
    {
        string temp="";
        for(ll j=0; j<vs[i].size(); j++)
        {
            bool f=0;
            if(j+1<vs[i].size())
            {
                if(vs[i][j]=='/' && vs[i][j+1]=='/')
                {
                    f=1;
                    if(vs[i].size()>=7 && j>=6)
                    {
                        if(vs[i].substr(j-7+1,7)=="printf(" ) f=0;
                    }
                    if(vs[i].size()>=8 && j>=7)
                    {
                        if(vs[i].substr(j-8+1,8)=="printf (" ) f=0;
                    }
                    if(vs[i].size()>=9 && j>=8)
                    {
                        if(vs[i].substr(j-9+1,9)==" printf(") f=0;
                    }
                }
                if(f) break;
            }
            temp+=vs[i][j];
        }
        ans.pb(temp);
    }
    return ans;
}
string SpaceRemoveWithLine1(vector<string> &vs)
{
    string ans="";
    char prev=' ';
    if(vs.size()>=1) ans+=vs[0];
    for(ll i=1; i<vs.size(); i++)
    {
        ans+=" ";
        ans+=vs[i];
    }
    prev=' ';
    string ans2="";
    for(ll i=0; i<ans.size(); i++)
    {
        if(prev==' ' && ans[i]==' ') continue;
        ans2+=ans[i];
        prev=ans[i];
    }
    return ans2;
}
vector<string> SpaceRemoveLine1(vector<string> &vs)
{
    vector<string> ans;
    for(ll i=0; i<vs.size(); i++)
    {
        string temp="";
        char prev='-';
        for(ll j=0; j<vs[i].size(); j++)
        {
            if(prev==' ' && vs[i][j]==' ' ) continue;
            temp+=vs[i][j];
            prev=vs[i][j];
        }
        ans.pb(temp);
    }
    return ans;
}

string FinalCommentRemove1(string &s)
{
    string ans="";
    ll f=0;
    for(ll i=0; i<s.length(); i++)
    {
        if(i+1<s.length())
        {
            if(s[i]=='/' && s[i+1]=='*') f=1;
        }
        if(i-1>=0)
        {
            if(s[i]=='/' && s[i-1]=='*')
            {
                f=0;
                continue;
            }
        }
        if(f) continue;
        ans+=s[i];
    }
    return ans;
}

void Assignment1()
{

    FileName.open("input.c",ios::in);
    vector<string>v,temp,temp2,temp3,temp4,temp5;
    string ans,ans2,ans3,ans4;
    if(!FileName)
    {
        cout<<"File doesn't exist";
    }
    else
    {
        string x;
        while(!FileName.eof())
        {
            getline(FileName,x);
            v.push_back(x);
            cout<<x<<endl;
        }
        FileName.close();
        File2.open("output1.txt",ios::out);
        if(!File2)
        {
            cout<<"Error\n";
        }
        else
        {
            temp=SpaceRemoveLine1(v);
            temp2=SideCommentRemove1(temp);
            ans=SpaceRemoveWithLine1(temp2);
            ans2=FinalCommentRemove1(ans);
            vector<string> tt,tt2;
            tt.pb(ans2);
            tt2=SpaceRemoveLine1(tt);
            for(ll i=0; i<tt2[0].size(); i++)
            {
                ans3.pb(tt2[0][i]);
            }
            cout<<ans3<<endl;
        }
        File2<<ans3;
        File2.close();
    }
}

bool isChar(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z')) return 1;
    else return 0;
}
bool isNum(char c)
{
    if(c>='0' && c<='9') return 1;
    else return 0;
}
void init()
{
    keywords2.pb("int");
    keywords2.pb("char");
    keywords2.pb("float");
    keywords2.pb("double");
    keywords2.pb("long");
    keywords2.pb("if");
    keywords2.pb("else");
    keywords2.pb("else if");
    keywords2.pb("const");
    keywords2.pb("inline");
    keywords2.pb("enum");
    keywords2.pb("char");
    keywords2.pb("goto");
    keywords2.pb("while");
    keywords2.pb("for");
    keywords2.pb("short");
    keywords2.pb("do");
    keywords2.pb("case");
    keywords2.pb("return");
    keywords2.pb("struct");
    keywords2.pb("continue");
    keywords2.pb("break");
    keywords2.pb("default");
    operators2.pb("=");
    operators2.pb("+");
    operators2.pb("-");
    operators2.pb("*");
    operators2.pb("/");
    operators2.pb("%");
    operators2.pb("+");
    operators2.pb("++");
    operators2.pb("--");
    operators2.pb("+=");
    operators2.pb("-=");
    operators2.pb("*=");
    operators2.pb("/=");
    operators2.pb("%=");
    operators2.pb("<<=");
    operators2.pb(">>=");
    operators2.pb("&=");
    operators2.pb("^=");
    operators2.pb("|=");
    operators2.pb("==");
    operators2.pb(">=");
    operators2.pb("<=");
    operators2.pb("!=");
    operators2.pb(">");
    operators2.pb("<");
    operators2.pb("&&");
    operators2.pb("||");
    operators2.pb("!");
    operators2.pb("^");
    operators2.pb("&");
    operators2.pb(">>");
    operators2.pb("<<");
    operators2.pb("~");
    parenthesis2.pb("{");
    parenthesis2.pb("}");
    parenthesis2.pb("(");
    parenthesis2.pb(")");
    parenthesis2.pb("[");
    parenthesis2.pb("]");
    separators2.pb(";");
    separators2.pb(",");
    separators2.pb("'");
}
bool checkkeywords2(string x)
{
    for(ll i=0; i<keywords2.size(); i++)
    {
        if(x==keywords2[i]) return true;
    }
    return false;
}
bool isParen(string s)
{
    for(ll i=0; i<parenthesis2.size(); i++)
    {
        if(s==parenthesis2[i])
        {
            return 1;
        }
    }
    return 0;
}
bool Identifier(string x)
{
    if(x[0]!='_' && !isChar(x[0])) return 0;
    ll len=x.length();
    for(ll i=1; i<len; i++)
    {
        if(x[i]!='_' && !isChar(x[i]) && !isNum(x[i])) return 0;
    }
    return 1;
}
bool NumericConstant(string s)
{
    if(s[0]!='-' && !isNum(s[0])) return 0;
    ll dot=0,b=0;
    ll len=s.length();
    ll pos=-1;
    if(s[0]=='-' && s.length()==1) return 0;
    for(ll i=1; i<len; i++)
    {
        if(isNum(s[i])) continue;
        if(s[i]=='.' )
        {
            b++;
            pos=i;
        }
        else return 0;
    }
    if(b>1) return 0;
    if(pos==-1) return 1;
    else
    {
        if(pos+1<len) return 1;
        else return 0;
    }
}
bool isOperator(string s)
{
    for(ll i=0; i<operators2.size(); i++)
    {
        if(s==operators2[i])
        {
            return 1;
        }
    }
    return 0;
}
bool isSeparator(string s)
{
    for(ll i=0; i<separators2.size(); i++)
    {
        if(separators2[i]==s) return 1;
    }
    return 0;
}
string LeximeSeparation(string s)
{
    string fin="";
    vector<ll> v,tt;
    ll j=0,k=0,i=0;
    ll len=s.length();
    for(; i<s.length();)
    {
        if(i+1<len && isOperator(s.substr(i,2)))
        {
            i+=2;
            continue;
        }
        if(!isNum(s[i]) && !isChar(s[i]) && s[i]!='_' && s[i]!='.' )
        {
            v.pb(i);
        }
        i++;
    }
    i=0;
    for(; i<s.length(); i++)
    {
        if(j<v.size())
        {
            if(i==v[j])
            {
                fin+=' ';
                fin+=s[i];
                fin+=' ';
                j++;
                continue;
            }
            else
            {
                fin+=s[i];
            }
        }
        else
        {
            fin+=s[i];
        }
    }
    string ans="";
    i=0;
    for(; i<fin.length();)
    {
        if(i+1<fin.length())
        {
            if(isOperator(fin.substr(i,2)))
            {
                ans+=" ";
                ans+=fin.substr(i,2);
                ans+=" ";
                i+=2;
                continue;
            }
            else
            {
                ans+=fin[i];
                i++;
            }
        }
        else
        {
            ans+=fin[i];
            i++;
        }
    }
    return ans;
}



void Assignment2()
{
    init();
    fstream file1,file2;
    file1.open("output1.txt",ios::in);
    if(!file1) {cout<<"File not found\n";return ;}
    string x,temp="";
    vector<string> vs;
    string k;
    ll r=0;
    while(!file1.eof())
    {
        getline(file1,x);
        if(x.length()>0)
        {
            k=x;
            cout<<k<<endl;
        }
    }
    file1.close();
    file2.open("output2.txt",ios::out);
    if(!file2) {cout<<"File not found\n";return ;}
    string step1=LeximeSeparation(k);
    cout<<"After step1="<<endl;
    cout<<step1<<endl;
    for(ll i=0; i<step1.length(); i++)
    {
        if(step1[i]==' ')
        {
            if(temp.size()>0) vs.pb(temp);
            temp="";
        }
        else temp+=step1[i];
    }
    string sk="";
    cout<<"final output\n";
    for(ll i=0; i<vs.size(); i++)
    {
        if(checkkeywords2(vs[i])) sk+="[kw "+vs[i]+"]";
        else if(NumericConstant(vs[i])) sk+="[num "+vs[i]+"]";
        else if(Identifier(vs[i]))sk+="[id "+vs[i]+"]";
        else if(isOperator(vs[i]))sk+="[op "+vs[i]+"]";
        else if(isSeparator(vs[i])) sk+="[sep "+vs[i]+"]";
        else if(isParen(vs[i])) sk+="[par "+vs[i]+"]";
        else sk+="[unkn "+vs[i]+"]";
    }
    file2<<sk;
    cout<<sk<<endl;
    file2.close();
    cout<<endl;
}

set<string> ase;
struct Symbol
{
    ll sl_no=-1;
    string name="",idtype="",datatype="",scope="",value="";
};
vector<Symbol> vs;
vector<string> idre;
ll mm=0;
ll gg=1;
string sg="global";

ll LookUp(string tt,ll i,string s)
{
    ll cc=-1;
    for(ll j=0; j<vs.size(); j++)
    {
        if(vs[j].name==tt && vs[j].scope==sg)
        {
            cc=j;
            break;
        }
    }
    string temp="";
    for(ll j=i-3; j>=0; j--)
    {
        if(s[j]!='[') temp+=s[j];
        else break;
    }reverse(temp.begin(),temp.end());
    ll k=tt.length();
    ll ff=i+3+k+2;

    if(ff<s.length())
    {

        if(s[ff]=='(')
        {
            if(ase.find(tt)!=ase.end()) {cc=-2;return cc;}
        }


    }

    return cc;


}

void Free()
{
    vs.clear();
}

void Insert(string tt,string s,ll i)
{

    Symbol ss;
    ss.sl_no=gg;
    gg++;
    ss.name=tt;
    string temp="";
    for(ll j=i-3; j>=0; j--)
    {
        if(s[j]!='[') temp+=s[j];
        else break;
    }reverse(temp.begin(),temp.end());

    if(temp=="double" || temp=="float" || temp=="char" || temp=="int")
    {
        ss.datatype=temp;
    }
    ll k=tt.length();
    ll ff=i+3+k+2;
    bool f=0;
    if(ff<s.length())
    {
        if(s[ff]=='(' ) {ss.idtype ="func";
        if(ase.find(tt)==ase.end()) { f=1;ase.insert(tt);}

        }
        else ss.idtype="var";
    }
    else ss.idtype="var";
    if(ff<s.length())
    {
        if(s[ff]=='=')
        {
            string mp="";
            for(ll j=ff+3; j<s.length(); j++)
            {
                if(s[j]==']') break;
                mp+=s[j];

            }
            ss.value=mp;
        }
    }
    /*if(mm==1) ss.scope="local";
    else if(mm==0) ss.scope="global";
    */
    ss.scope=sg;
    if(f) sg=tt;

    vs.pb(ss);
}

void Display()
{
    cout<<"Sl. No. - Name - Id Type - Data Type - Scope - Value\n";

    for(ll i=0;i<vs.size();i++)
    {
        cout<<vs[i].sl_no<<" "<<vs[i].name<<" "<<vs[i].idtype<<" "<<vs[i].datatype<<" "<<vs[i].scope<<" "<<vs[i].value<<endl;
    }
}

void SetAttribute(string attname,string value,ll idx){if(attname=="Name"){vs[idx].name=value;}if(attname=="Id Type"){vs[idx].idtype=value;}if(attname=="Data Type"){vs[idx].datatype=value;}if(attname=="Scope"){vs[idx].scope=value;}if(attname=="Value"){vs[idx].value=value;}}
void Step2(string s)
{
    cout<<"Step 2\n";
    for(ll i=0;i<s.length()-2;i++)
    {
        if(s[i]=='}') sg="global";

        if(s.substr(i,3)=="id ")
        {

            string tt="";
            for(ll j=i+3;j<s.length();j++)
            {
                 if(s[j]==']') break;
                 tt+=s[j];
            }
            //deb(tt);
            ll cc=LookUp(tt,i,s);

            if(cc==-1)
            {
                Insert(tt,s,i);
            }
            else if(cc==-2)
            {

            }
            else
            {
                ll k=tt.length();
                ll ff=i+3+k+2;
                if(ff<s.length())
                {
                    if(s[ff]=='=')
                    {
                        string mp="";
                        for(ll j=ff+3; j<s.length(); j++)
                        {
                            if(s[j]==']') break;
                            if((s[j]>='0' && s[j]<'9') || s[j]=='.')  mp+=s[j];
                                else break;

                        }
                        if(cc!=-1 && cc!=-2) SetAttribute("Value",mp,cc);
                    }
                }
            }



        }
    }
    Display();
}

string Step1(string s)
{

    string temp="";
    vector<string> vs;
    vs.pb("op ");vs.pb("kw ");vs.pb("par ");vs.pb("sep ");vs.pb("num ");vs.pb("brc ");
    vector<pair<ll,ll> > v;
    for(ll i=0;i<vs.size();i++)
    {
        ll sz=vs[i].length();
        //s.erase()

        for(ll k=0;k<s.length()-sz+1;k++)
        {
            if(s.substr(k,sz)==vs[i])
            {
                for(ll j=k;j<k+sz;j++)
                {
                    s[j]='%';
                }
            }


        }


    }
    string t="";
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]!='%') t+=s[i];
    }


    return t;
}

string Step4(string s)
{
    string temp,sp="global";string s2=s;set<string > ase;
    for(ll i=0;i<s.length();i++)
    {
        if(s2[i]=='(')
        {
            string tn="";
            for(ll k=i-3;k>=0;k--)
            {
                if(s2[k]==' ' || s2[k]=='%') break;
                tn+=s2[k];
            }
            reverse(tn.begin(),tn.end());
            if(ase.find(tn)==ase.end()){
            sp=tn;
            ase.insert(tn);}
        }
        if(s2[i]=='}') sp="global";
        for(ll j=0;j<vs.size();j++)
        {
            ll sz=vs[j].name.length();
            if(i+sz<=s.length())
            {
                if(vs[j].name==s.substr(i,sz) && ((vs[j].scope==sp && vs[j].idtype=="var") || (vs[j].idtype=="func") ))
                {
                    char c='0'+vs[j].sl_no;
                    s[i]=c;
                    //deb(i);deb(c);

                    for(ll k=i+1;k<i+sz;k++)
                    {
                        s[k]='%';
                    }
                    //cout<<"h=";deb(s);
                    break;
                }
            }
        }
    }
    for(ll i=0;i<s.length();i++)
    {
        if(s[i]!='%') temp+=s[i];
    }
    return temp;
}
void Assignment3()
{
     fstream file1,file2;
    file1.open("output2.txt",ios::in);
    if(!file1) {cout<<"File not found\n";return ;}
    string x,temp="";
    vector<string> vss;
    while(!file1.eof())
    {
        getline(file1,x);
        vss.pb(x);
        temp+=x;
    }
    file1.close();
    cout<<temp<<endl;
    cout<<"\n\n";
    cout<<"Step 1"<<endl;
    string ff=Step1(temp);
    cout<<ff<<endl;
    Step2(ff);
    cout<<"\n\n";
    string kk=Step4(ff);
    file2.open("output3.txt",ios::out);
    string sk=kk;
    cout<<"final output\n";
    file2<<sk;cout<<sk<<endl;file2.close();cout<<endl;
}

vector<string>v,temp,temp2,temp3,temp4,temp5;
set<string> key_word;
string ans,ans2,ans3,ans4;
stack<ll > st1,st2,st3;
void Key()
{
    key_word.insert("int");
    key_word.insert("char");
    key_word.insert("float");
    key_word.insert("double");
    key_word.insert("long");
}
void FinalCommentRemove()
{
    vector<string> vs,vt;
    vs=v;
    v.clear();
    bool f=1;
    for(ll i=0; i<vs.size(); i++)
    {
        string temp="";
        ll j=0;
        for(; j<vs[i].length();)
        {

            if(vs[i][j]=='/' && vs[i][j+1]=='/') {break;}
            if(vs[i][j]=='/' && vs[i][j+1]=='*')
            {
                f=0;
                j+=2;
            }
            if(vs[i][j]=='*' && vs[i][j+1]=='/')
            {
                f=1;
                j+=2;
            }
            if(f==0)
            {
                j++;
                continue;
            }
            temp+=vs[i][j];
            j++;
        }
        v.pb(temp);
    }
}
string F(int i)
{
    string s="";
    if(i+1>=10)
    {
        char p=((i+1)/10)+'0';
        s+=p;
        p=(i+1)%10+'0';
        s+=p;
    }
    else
    {
        char p=(i+1)%10+'0';
        s+=p;
    }
    return s;
}
void CheckPar()
{
    for(ll i=0; i<v.size(); i++)
    {
        for(ll j=0; j<v[i].length(); j++)
        {
            if(v[i][j]=='(') st1.push(i+1);
            if(st1.empty() && v[i][j]==')')
            {
                cout<<"Misplaced ) at line "<<i+1<<endl;
                ans2+="Misplaced ) at line ";
                ans2+=F(i);
                ans2+="\n";
            }
            if(v[i][j]==')' && !st1.empty()) st1.pop();
            if(v[i][j]=='{') st2.push(i+1);
            if(st2.empty() && v[i][j]=='}')
            {
                cout<<"Misplaced } at line "<<i+1<<endl;
                ans2+="Misplaced } at line ";
                ans2+=F(i);
                ans2+="\n";
            }
            if(v[i][j]=='}' && !st2.empty()) st2.pop();
            if(v[i][j]=='[') st3.push(i+1);
            if(st3.empty() && v[i][j]==']')
            {
                cout<<"Misplaced ] at line "<<i+1<<endl;
                ans2+="Misplaced ] at line ";
                ans2+=F(i);
                ans2+="\n";
            }
            if(v[i][j]==']'&& !st3.empty()) st3.pop();
        }
    }
    while(!st1.empty())
    {
        cout<<"Extra ( at line "<<st1.top()<<endl;
        ans2+="Extra ( at line ";
        ans2+=F(st1.top());
        ans2+="\n";
        st1.pop();
    }
    while(!st2.empty())
    {
        cout<<"Extra { at line "<<st2.top()<<endl;
        ans2+="Extra { at line ";
        ans2+=F(st2.top());
        ans2+="\n";
        st2.pop();
    }
    while(!st3.empty())
    {
        cout<<"Extra [ at line "<<st3.top()<<endl;
        ans2+="Extra [ at line ";
        ans2+=F(st3.top());
        ans2+="\n";
        st3.pop();
    }
}
void UnmatchedIFELSE()
{
    bool f=0;
    for(ll i=0; i<v.size(); i++)
    {
        string temp=v[i];
        for(ll j=0; j<v[i].size(); j++)
        {
            if(v[i].substr(j,2)=="if") f=1;
            if(v[i].substr(j,4)=="else")
            {
                if(f==1) f=0;
                else
                {
                    cout<<"Unmatched else at line "<<i+1<<endl;
                    ans2+="Unmatched else at line ";
                    ans2+=F(i);
                    ans2+="\n";
                }
            }
        }
    }
}

bool IsToken(char c)
{
    if(c==';') return 1;
    else return 0;
}
void DuplicateToken()
{
    for(ll i=0; i<v.size(); i++)
    {
        for(ll j=0; j<v[i].length(); j++)
        {
            if(v[i][j]==v[i][j+1] && IsToken(v[i][j]))
            {
                cout<<"Duplicate Token at line "<<i+1<<endl;
                ans2+="Duplicate Token at line ";
                ans2+=F(i);
                ans2+="\n";
            }
        }
    }
}

void DuplicateIdentifier()
{
    string temp="";
    vector<pair<string,ll> >  tt;
    for(ll i=0; i<v.size(); i++)
    {
        for(ll j=0; j<v[i].size(); j++)
        {
            if(v[i][j]==' ')
            {
                tt.pb({temp,i+1});
                temp="";
                continue;
            }
            temp+=v[i][j];
        }
        tt.pb({temp,i+1});
        temp="";
    }
    for(ll i=0; i<tt.size()-1; i++)
    {
        if(tt[i].first==tt[i+1].first && key_word.find(tt[i].first)!=key_word.end() && key_word.find(tt[i+1].first)!=key_word.end() )
        {
            cout<<"Duplicate type at line ";
            cout<<tt[i].second<<endl;
            ans2+="Duplicate type at line ";
            ans2+=F(tt[i].second-1);
            ans2+="\n";
        }
    }
}
void Print()
{
    ans3="";
    for(ll i=0; i<v.size(); i++)
    {
        cout<<i+1<<".";
        ans3+=F(i);
        ans3+='.';
        for(ll j=0; j<v[i].length(); j++)
        {
            ans3+=v[i][j];
            cout<<v[i][j];
        }
        ans3+='\n';
        cout<<endl;
    }
}


void Assignment4()
{
    ifstream FileName;
    fstream File2,File3;
    FileName.open("input.c",ios::in);
    if(!FileName)
    {
        cout<<"File doesn't exist";
    }
    else
    {
        string x;
        while(!FileName.eof())
        {
            getline(FileName,x);
            cout<<x<<endl;
            if(x.length()>0 ) v.push_back(x);
        }
        Key();
        vector<string> ans=v;
        FileName.close();
        FinalCommentRemove();
        Print();
        UnmatchedIFELSE();
        CheckPar();
        DuplicateToken();
        DuplicateIdentifier();

        File3.open("output4.txt",ios::out);
        File3<<ans3;
        File3.close();
        File2.open("output5.txt",ios::out);
        if(!File2)
        {
            cout<<"Error\n";
        }
        else
        {
            File2<<ans2;
            File2.close();
        }
    }

}
int main()
{
    cout<<"(            1st procedure                )\n\n\n\n ";
    Assignment1();
     cout<<"(           2nd procedure                )\n\n\n\n ";
    Assignment2();
     cout<<"(            3rd procedure                )\n\n\n\n ";
    Assignment3();
    cout<<"(            4th procedure                )\n\n\n\n ";
    Assignment4();




    return 0;
}


