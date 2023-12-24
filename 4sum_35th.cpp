#include <iostream>

/*
                        Q. 4 sum problem

                    explanation -  we have to find 4 indexes to get to the target value
                                    num[i] + num[j] + num[k] + num[l] = target
                                also -  [i != j != k != l]

                        exa -  lets take an example  arr[] = {1, 0, -1, 0, -2, 2}   target = 0
                                o/p - {-2, -1, 1, 2},  {-2, 0, 0, 2},  {-1, 0, 0, 1}

                Brute force -  similar to 3sum's brute force

    Actual code
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                for(int l = k + 1; l < n; l++)
                {
                    long long sum = nums[i] + nums[j];              // <- nums limit might get exceed, thats why we are breaking it into different steps
                    sum += nums[k];
                    sum += nums[l];
                    
                    if(sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vetor<int>> ans(st.begin(), st.end());
    return ans;
}

                TC - O(N^4)
                SC - O(nmbr of quads) * 2


                Better sol -  nums[l] = target -(nums[i] + nums[j] + nums[k]) 
                                we will do as we have done in 3sum problem by creating hash table

        Actual code
vector<vector<int>> fourSum(vector<int>& num, int target)
{
    int n = num.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            set<int> hashset;
            for(int k = j + 1; k < n; k++)
            {
                long long sum = num[i] + num[j];
                sum += num[k];
                long long fourth = target - sum;

                if(hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {num[i], num[j], num[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(num[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

                TC - O(N^3 * log M)
                SC - O(N) + O(quads)*2


                Optimal sol -  arr[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5}   target = 8
                                same as we did in 3sum problem

        Actual code
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++)
    {
        if(i > 0 && nums[i] == nums[i - 1])
            continue;

        for(int j = i + 1; j < n; j++)
        {
            if(j != i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;

            while(k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];

                if(sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push(temp);
                    k++, l--;

                    while(k < l && nums[k] == nums[k - 1])
                        k++;
                    while(k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if(sum < target)
                    k++;
                else
                    l--;
            }
        }
    }
    return ans;
}

            TC - O(N^2) * O(N)                 // for i&j * for k
            SC - O(nmbr of quads)               // to return the ans
*/

int main()
{
    std::cout << "Hello World!\n";
}