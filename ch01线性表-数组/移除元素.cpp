class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int p = 0, q = nums.size() - 1;
        while (p <= q)
        {
            //找到需要交换的数
            // while (p < q)
            // {
            //     if (nums[q] != val)
            //         break;
            //     q--;
            // }
            //q找到一个不等于val的值与p等于val的值交换 最后p移动的位置就是非val的位置
            if (nums[q] == val)
            {
                q--;
                continue;
            }

            if (nums[p] == val)
            {
                nums[p] = nums[q];
                q--;
            }
            else
            {
                p++;
            }
        }
        // if (nums.size() == 0)
        // {

        //     return 0;
        // }
        // if (nums[p] != val)
        // {
        //     return p + 1;
        // }
        // else
        // {
        //     return p;
        // }
        return p;
    }
};