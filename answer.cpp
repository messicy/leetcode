using namespace std;
#include <vector>
#include <set>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> base;
				set<int> result;

				for(int i = 0; i < nums1.size(); i++)
				{
					base.insert(nums1[i]);
				}
				
				for(int i = 0; i < nums2.size(); i++)
				{
					set<int>::iterator ite1 = base.find(nums2[i]);
    			if(ite1!=base.end())
					{
						result.insert(nums2[i]);
					}
				}
				
				vector<int> ret( result.begin(), result.end() );

				return ret;
    }
};