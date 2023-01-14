//
// Created by Cyril Wong on 1/13/23.
//
#include <vector>

using namespace std;


class Solution {
 public:
  /**
   * Same problem: https://leetcode.cn/problems/sort-an-array/
   * @param nums
   * @return
   */
  vector<int> sortArray(vector<int>& nums) {
    QuickSort(nums, 0, nums.size() - 1);
    return nums;
  }

  /**
   * 3-way quick sort
   * https://www.runoob.com/data-structures/3way-qiuck-sort.html
   * @brief 3-way quick sort is robust when the input array contains a lot of duplicates. e.g. all numbers are 2.
   *        randomization help quick sort avoid degenerate to O(n^2) when the input array is sorted.
   *        Future improvement can be using insertion sort when the input array size < 10 elements.
   * @param nums
   * @param left
   * @param right
   */
  void QuickSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
      return;
    }

    // randomization
    int pivot_index = rand() % (right - left + 1) + left;
    Swap(nums, right, pivot_index);

    // 3-way quick sort
    int pivot = nums[right];
    int lt = left - 1;
    int gt = right;
    int i = left;
    while (i < gt) {
      if (pivot == nums[i]) {
        i++;
      } else if (pivot > nums[i]) {
        Swap(nums, i++, ++lt);
      } else {
        Swap(nums, i, --gt);
      }
    }
    Swap(nums, right, i);

    // only perform subsequence quick sort on less than and greater than area
    QuickSort(nums, left, lt);
    QuickSort(nums, i + 1, right);
  }

  void Swap(vector<int>& nums, int a, int b) {
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
  }
};

auto main() -> int {
  vector<int> nums{5,2,3,1};

  Solution sol;
  sol.sortArray(nums);
}