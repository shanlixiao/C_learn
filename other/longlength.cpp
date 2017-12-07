#include <iostream>
using namespace std;

class Solution
{
	public:
		int length(string s){
			int i,j,n;
			string max,b;
			max = " ";
			for(i = 0;i < s.size();i++)
			{
				b[0] = s[i];
				for(j = i + 1;j < s.size();j++)
				{
					if(s[j] != s[i])
						b[j - i] = s[j];
				}
				if (b.size() > max.size())
					max = b;
			}
			n = max.size();
			return n;
		}
};
int main(){
	string a = "abcd";
	Solution A;
	cout<<A.length(a)<<endl;
}
