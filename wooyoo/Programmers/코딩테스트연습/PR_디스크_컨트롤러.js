// 우선순위큐를 이용하여 풀면 좋지만, JS에는 없으니, 시간 복잡도가 길어도 정렬로 풀라한다.
// 시작 시간 순 정렬
// (우선순위) 큐에 실행 시간이 짧은 순으로 넣는다
// 큐에서 하나 씩 빼면서 실행, 실행 후에 다시 늘어난 시간만큼 큐에 넣는다

const sortByStartTime = (a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]);
// const sortByRunTime = (a, b) => a[1] - a[0] - (b[1] - b[0]);
const sortByRunTime = (a, b) => a[1] - b[1];

const runJob = (currentTime, job, currentOperatedTime) => {
  return [currentTime + job[1], currentTime + job[1] - job[0] + currentOperatedTime];
};

const getAvailJobs = (availJobs, jobs, currentTime) => {
  while (jobs.length) {
    let job = jobs[0];
    if (job[0] > currentTime) {
      break;
    }
    jobs.shift();
    availJobs.push(job);
  }
  availJobs.sort(sortByRunTime);
};

function solution(jobs) {
  let jobCount = jobs.length;
  jobs.sort(sortByStartTime);
  const availJobs = [];
  let currentTime = 0;
  let currentOperatedTime = 0;

  while (jobs.length || availJobs.length) {
    getAvailJobs(availJobs, jobs, currentTime);
    if (availJobs.length === 0) {
      currentTime += 1;
      continue;
    }
    let job = availJobs.shift();
    [currentTime, currentOperatedTime] = runJob(currentTime, job, currentOperatedTime);
  }
  return Math.floor(currentOperatedTime / jobCount);
}
