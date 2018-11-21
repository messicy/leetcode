using namespace std;
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>

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
		int i = 0;
		string ss(s);
		while (i != c.length())
		{
			int j = ss.find_first_of(c[i]);

			if (j != string::npos)
			{
				ss = ss.substr(j, ss.length());
			}
			else
			{
				return false;
			}

			i++;
		}
		return true;
	}

	static bool compare(const string &a, const string &b)
	{
		if (a.length() > b.length())
		{
			return true;
		}
		else if (a.length() < b.length())
		{
			return false;
		}
		else
		{
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

	int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
	{
		map<int, int> noduplicate;
		
		for(int i = 0; i < D.size(); i++)
		{
			
		}
		
		int count = 0;
		for(int i = 0; i < A.size(); i++)
		{
			for(int j = 0; j < B.size(); j++)
			{
				for(int k = 0; k < C.size(); k++)
				{
					int left = -(A[i] + B[j] + C[k]);
					vector<int>::iterator ite1 = find(D.begin(), D.end(), left);
					
					if (ite1 != D.end()) {
						count++;
					}
					
				}
			}
		}

		return count;
	}

	bool binarySearch(vector<int> &A, int target)
	{

	}
};
