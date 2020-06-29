// 프로그래머스 소수 만들기
// 완전탐색 + 에라토스테네스의 체로 소수 빨리 구하는 문제

#include <vector>
#include <iostream>

using namespace std;

// 에라토스테네스의 체로 소수 판별 배열 생성
bool isNotPrime[3001];

int bruteForce(int start, vector<int> nums, int checkSum, int sum)
{
    if (checkSum == 3)
    {
        return !isNotPrime[sum];
    }
    int ret = 0;
    for (int i = start; i < nums.size(); i++)
    {
        ret += bruteForce(i + 1, nums, checkSum + 1, sum + nums[i]);
    }
    return ret;
}

int solution(vector<int> nums)
{
    int answer = 0;

    for (int i = 2; i <= 3000; i++)
    {
        for (int j = 2; i * j <= 3000; j++)
        {
            isNotPrime[i * j] = true;
        }
    }

    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        answer += bruteForce(i + 1, nums, 1, nums[i]);
    }

    return answer;
}