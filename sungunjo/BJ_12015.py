def lowerBound(nums, k):
	left = 0;
	right = len(nums) - 1;
	
	while (left <= right):
		mid = int((left + right) / 2);

		if (k <= nums[mid]):
			right = mid - 1;
			lower_bound = mid;
		else:
			left = mid + 1;
	return lower_bound;

N = int(input());

nums = [int(x) for x in input().split(' ')];

lis = [nums[0]];

for num in nums:
	if (lis[-1] < num):
		lis.append(num);
	elif (num < lis[-1]):
		idx = lowerBound(lis, num);
		lis[idx] = num;

print(len(lis));
	