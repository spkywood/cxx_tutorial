#ifndef _MYSORT_H_
#define _MYSORT_H_

#pragma once

#include <iostream>
#include <vector>
#include <time.h>
#include <utility>

class MySort {
public:

	void bubble(std::vector<int>&);
	void insertion(std::vector<int>&);
	void selection(std::vector<int>&);
	void quick(std::vector<int>&, size_t, size_t);
	void heap(std::vector<int>&);

	/*
	void shell(vector<int>&);
	void merge(vector<int>&);
	*/
	//void test();
private:
	void max_heapify(std::vector<int>&, size_t);
};


/**
* 冒泡排序，最大值依次往后调整。
*/
void MySort::bubble(std::vector<int>& nums) {
	for (size_t i = 0; i < nums.size(); i++)
	{
		for (size_t j = 0; j < nums.size()-i-1; j++)
		{
			if (nums[j] > nums[j+1])
			{
				std::swap(nums[j], nums[j+1]);
			}
		}
	}
}


/**
* 插入排序，从后往前插入已排序好的队列
*/
void MySort::insertion(std::vector<int>& nums) {
	for (size_t i = 1; i < nums.size(); i++)
	{
		size_t j = i;
		while (j > 0)
		{
			if (nums[j] >= nums[j-1]) {
				break;
			}
			else // (nums[j] < nums[j-1])
			{
				std::swap(nums[j-1], nums[j]);
			}
			--j;
		}
	}
}

/**
* 选择排序，每次选择一个最小值，减少交换次数
*/
void MySort::selection(std::vector<int>& nums) {
	for (size_t i = 0; i < nums.size(); i++)
	{
		size_t min_index = i;
		for (size_t j = i+1; j < nums.size(); j++)
		{
			if (nums[j] < nums[min_index]) {
				min_index = j;
			}
		}

		std::swap(nums[i], nums[min_index]);
	}
}

/**
* 快速排序，找到一个pivot基准值，把小于基准值的放右边，大于基准值的放左边，依次递归实现
*/
void MySort::quick(std::vector<int>& nums, size_t low, size_t high) {
	if (low >= high) {
		return;
	}

	size_t left = low;
	size_t right = high;
	int pivot = nums[left];

	// 选择第一个值作为基准值
	// 从后往前，找第一个小于基准值的值，将其值调换到前面。
	// 从前往后，找第一个大于基准值的值，将其值调换到后面
	while (left < right) {
		while (left < right && nums[right] >= pivot) {
			--right;
		}
		nums[left] = nums[right];
		while (left < right && nums[left] <= pivot) {
			++left;
		}
		nums[right] = nums[left];
	}
	nums[left] = pivot;

	quick(nums, low, left - 1);
	quick(nums, left + 1, high);
}

/**
* 堆排序算法；用数组的形式去模拟一个最小堆
* 或者STL中的优先级队列
*/

void MySort::heap(std::vector<int>& nums) {
	for (size_t i = nums.size(); i > 0; --i)
	{
		max_heapify(nums, i);

		// 堆顶元素和Kn交换
		std::swap(nums[0], nums[i-1]);
	}
}

void MySort::max_heapify(std::vector<int>& nums, size_t limit) {
	size_t length = nums.size();
	if (length < 0 || length < limit) {
		return;
	}

	int parent_idx = static_cast<int>(limit) >> 1;
	for (; parent_idx >= 0; parent_idx--)
	{
		if (parent_idx * 2 >= limit) {
			continue;
		}

		int left = parent_idx * 2;
		int right = (left + 1) >= limit ? left : (left + 1);

		int max_child_idx = nums[left] > nums[right] ? left : right;
		if (nums[max_child_idx] > nums[parent_idx]) {
			std::swap(nums[parent_idx], nums[max_child_idx]);
		}
	}
}


#endif