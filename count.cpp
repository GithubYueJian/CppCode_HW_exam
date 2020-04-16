#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <unordered_map>
#include<map>
#include <utility>
using namespace std;
struct VOTE{
	std::string name;
	unsigned int num;
};
vector<string> read()
{
	
	string str;
	string temp;
	vector<string> strs;
	cin>>str;
	for(int i=0;i<=str.size();++i)
	{
		if(str[i]!=',')
			temp.push_back(str[i]);
		if(str[i]==','||str[i]=='\0')
		{
            strs.push_back(temp);
			temp="";
		}

	}
	return strs;
}

int main()
{
	vector<string> strs;
	strs=read();      //读取数据
	unordered_map<string, unsigned int> people;    //建立哈希表
	for(vector<string>::iterator it=strs.begin();it!=strs.end();++it)    //如果key不存在，建立key，对应的value=1；如果对应的key存在，对应的value+1
	{
			if (people.find(*it) == people.end()) 
                people[*it] = 1;
            else
                people[*it]++;
	}
    
	for(unordered_map<string, unsigned int>::iterator iter = people.begin(); iter != people.end(); iter++){
        cout << iter->first << " : " << iter->second << endl;
    }
	
	VOTE v;
	vector<VOTE> vs; //把哈希表内容装到vs里面
	for(unordered_map<string, unsigned int>::iterator iter = people.begin(); iter != people.end(); iter++){
        v.name=iter->first;
		v.num=iter->second;
		vs.push_back(v);
    }
	cout<<"map to vec"<<endl;
    for(vector<VOTE> ::iterator it=vs.begin();it!=vs.end();++it)
	{
		cout<<"name:"<<it->name<<endl;
		cout<<"num:"<<it->num<<endl<<endl;
	} 
	
	for(vector<VOTE> ::iterator it=vs.begin();it!=vs.end();++it)  //对vs 按照得票数排序
	{
        for(vector<VOTE> ::iterator itt=it+1;itt!=vs.end();++itt)
		{
			if((itt->num)>(it->num))
				swap(*itt,*it);
		}
	} 
	
	cout<<"sort by value"<<endl;
    for(vector<VOTE> ::iterator it=vs.begin();it!=vs.end();++it)
	{
		cout<<"name:"<<it->name<<endl;
		cout<<"num:"<<it->num<<endl<<endl;
	} 
	VOTE end;
	if(vs[0].num!=vs[1].num)
	{
		end.num=vs[0].num;
		end.name=vs[0].name;
	}
	else
	{
		vector<VOTE> temp;
	    for(int i=0;i<vs.size();++i)  
	    {
            if(vs[i].num!=vs[i+1].num)
			{
				for(int j=0;j<=i;++j)
					temp.push_back(vs[i]);
			}
	    } 
		vs=temp;
		for(vector<VOTE> ::iterator it=vs.begin();it!=vs.end();++it)  //对vs 按照name,a在前b在后 
	    {
            for(vector<VOTE> ::iterator itt=it+1;itt!=vs.end();++itt)
		    {
			
		    	if(((itt->name)<(it->name)))    //a在前b在后
		    		swap(*itt,*it);
				
				if((it->name).find(itt->name)==0)    //Tom 在前 Tomy在后
		    		swap(*itt,*it);
		    }
	    }
		end.num=vs[0].num;
		end.name=vs[0].name;
		
	}
	cout<<"end"<<endl;
	cout<<" name: "<<end.name<<" num: "<<end.num<<endl;
	

	
	return 0;






}
