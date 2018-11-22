using namespace std;
#include <vector>
#include <set>
#include <string>
#include <algorithm>

class Solution
{
public:
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
	{
		set<int> base;
		set<int> result;

		for (int i = 0; i < nums1.size(); i++)
		{
			base.insert(nums1[i]);
		}

		for (int i = 0; i < nums2.size(); i++)
		{
			set<int>::iterator ite1 = base.find(nums2[i]);
			if (ite1 != base.end())
			{
				result.insert(nums2[i]);
			}
		}

		vector<int> ret(result.begin(), result.end());

		return ret;
	}

	static bool isSubWord(string s, string c)
	{
		int j = 0;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == c[j])
			{
				j++;
			}

			
			if (j == c.length) {
				return true;
			}
		}
		
		return false;
	}

	static bool compare(const string& a, const string& b)
	{
		if (a.length() > b.length()) {
			return true;
		}
		else if(a.length() < b.length()) {
			return false;
		}
		else {
			return a.compare(b) < 0;
		}
	}

	string findLongestWord(string s, vector<string> &d)
	{
		sort(d.begin(), d.end(), compare);
		for (int i = 0; i < d.size(); i++)
		{
			if (isSubWord(s, d[i]))
				return d[i];
		}
		return "";
	}
};
