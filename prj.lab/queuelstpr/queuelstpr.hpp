#pragma once
#ifndef QUEUELSTPR_QUEUELSTPR_HPP_20240307
#define QUEUELSTPR_QUEUELSTPR_HPP_20240307

#include <cstddef>

class QueueLstPr {
public:
    QueueLstPr() = default;

    QueueLstPr(const QueueLstPr& copy);
    QueueLstPr(QueueLstPr&& copy) noexcept;

    ~QueueLstPr() = default;

    [[nodiscard]] QueueLstPr& operator=(const QueueLstPr& copy);
    [[nodiscard]] QueueLstPr& operator=(QueueLstPr&& copy);

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const float& val);

    [[nodiscard]] float& Top();

    [[nodiscard]] const float& Top() const;

    void Clear() noexcept;

private:
    struct Node {
        float val;
        Node* next = nullptr;
    };

    Node* head_ = nullptr;  
    int size_ = 0;
};

#endif