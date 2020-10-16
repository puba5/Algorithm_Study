import math

def getJobTimes(progresses, speeds, num_of_job):
    job_times = []
    
    for i in range(0, num_of_job):
        remain_rate = 100 - progresses[i]
        job_time = math.ceil(remain_rate / speeds[i])
        job_times.append(job_time)
        
    return job_times

def distribute(job_times, num_of_job):
    time = job_times[0]
    cnt = 1
    distributed_cnt_list = []
    for i in range(1, num_of_job):
        if job_times[i] > time:
            distributed_cnt_list.append(cnt)
            time = job_times[i]
            cnt = 1
        else:
            cnt += 1
            
    distributed_cnt_list.append(cnt)
    
    return distributed_cnt_list
        

def solution(progresses, speeds):
    answer = []
    
    num_of_job = len(progresses)
    
    job_times = getJobTimes(progresses, speeds, num_of_job)
    
    answer = distribute(job_times, num_of_job)

        
    
    
    return answer