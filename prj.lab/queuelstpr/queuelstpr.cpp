#include <queuelstpr/queuelstpr.hpp>

#include <stdexcept>
#include <limits>


QueueLstPr::QueueLstPr(const QueueLstPr& copy) {
    size_ = copy.size_;
    Node* now = copy.head_;
    Node* old_now = nullptr;
    head_ = new Node{ now->val };
    old_now = head_;
    for (int i = 0; i < size_-1; i++) {
        old_now->next = new Node{ now->val };
        now = now->next;
        old_now = old_now->next;
    }
}
QueueLstPr::QueueLstPr(QueueLstPr&& copy) noexcept {
    std::swap(*this, copy);
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& copy) {
    size_ = copy.size_;
    Node* now = copy.head_;
    Node* old_now = nullptr;
    head_ = new Node{ now->val };
    old_now = head_;
    for (int i = 0; i < size_ - 1; i++) {
        old_now->next = new Node{ now->val };
        now = now->next;
        old_now = old_now->next;
    }
    return *this;
}

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& copy) {
    std::swap(*this, copy);
    return *this;
}

bool QueueLstPr::IsEmpty() const noexcept {
    return nullptr == head_;
}

void QueueLstPr::Pop() noexcept {
    if (!IsEmpty()) {
        Node* deleted = head_;
        head_ = head_->next;
        delete deleted;
        size_--;
    }
}

void QueueLstPr::Push(const float& val) {
    if (IsEmpty()) {
        head_ = new Node{ val };
        size_++;
    }
    else {
        Node* now_ = head_;
        Node* now_back = nullptr;
        if (size_ >= 2) {
            for (int i = 0; i < size_; i++) {
                if (now_->val < val) {
                    now_back = now_;
                    now_ = now_->next;
                    continue;
                }
                if (std::abs((now_->val) - val) < std::numeric_limits<float>::epsilon()) {
                    if (now_back != nullptr) {
                        Node* now_back_old_next = now_back->next;
                        now_back->next = new Node{ val, now_back_old_next->next };
                        break;
                    }
                    else {
                        throw std::logic_error("nowback == nullptr");
                    }

                }
            }
        }
        else {
            if (now_->val < val) {
                now_->next = new Node{ val };
                size_++;
            }
            else {
                Node* old_head = head_;
                head_ = new Node{ val,old_head };
                old_head->next = nullptr;
            }
        }
    }
}

float& QueueLstPr::Top() {
    if (IsEmpty()) {
        throw std::logic_error("QueueLstPr - try get top from empty queue.");
    }
    return head_->val;
}

const float& QueueLstPr::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("QueueLstPr - try get top from empty queue.");
    }
    return head_->val;
}

void QueueLstPr::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}