#include <stddef.h>

#include "types.h"
#include "task.h"


void Task::on_task_ready(void) {
    c_ = C_;
    d_ = D_;
    r_ = T_;
    cnt_++;
}

void Task::on_task_start(void) {
    //cout << "t:" << kernel_cnt << ", r" << '(' << id_ << ',' << cnt_ << ')' << '\n';
    if (onstart_hook_ != NULL) {
        onstart_hook_();
    }
}


void Task::on_task_finish(void) {
    //cout << "t:" << kernel_cnt << ", f" << '(' << id_ << ',' << cnt_ << ')' << '\n';
    if (onfinish_hook_ != NULL) {
        onfinish_hook_();
    }
}

void Task::set_onstart_hook(callback onstart)
{
    onstart_hook_ = onstart;
}

void Task::set_onfinish_hook(callback onfinish)
{
    onfinish_hook_ = onfinish;
}

void Task::repr()
{
    //std::cout << id_ << ":" << task_status_literal[status_] << " | " << c_ << " | " << d_<< " | " << r_ << "\n";
}