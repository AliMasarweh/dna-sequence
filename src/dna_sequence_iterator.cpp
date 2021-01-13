//
// Created by ali-masa on 1/13/21.
//

#include "../header/dna_sequence.h"

using iterator=DNASequence::iterator;
iterator::iterator(std::vector<Nucleotide>& m_sequence, size_t index): m_sequenceReference(m_sequence),
                                                                       m_index(std::min(index, m_sequence.size())) {}

iterator::iterator(const std::vector<Nucleotide>& m_sequence, size_t index)
        : m_sequenceReference(const_cast<std::vector<Nucleotide>&>(m_sequence)), m_index(index) {}

Nucleotide &iterator::operator*() {
    if(m_index > m_sequenceReference.size()) { throw std::exception(); }

    return m_sequenceReference[m_index];
}

const Nucleotide &iterator::operator*() const {
    if(m_index > m_sequenceReference.size()) { throw std::exception(); }

    return m_sequenceReference[m_index];
}

Nucleotide *iterator::operator->() {
    if(m_index > m_sequenceReference.size()) { throw std::exception(); }

    return &(m_sequenceReference[m_index]);
}

const Nucleotide *iterator::operator->() const {
    if(m_index > m_sequenceReference.size()) { throw std::exception(); }

    return &(m_sequenceReference[m_index]);
}

iterator &iterator::operator++() {
    ++m_index;
    return *this;
}

const iterator &iterator::operator++() const {
    ++m_index;
    return *this;
}

iterator iterator::operator++(int) {
    iterator it(m_sequenceReference, m_index++);
    return it;
}

const iterator iterator::operator++(int) const {
    iterator it(m_sequenceReference, m_index++);
    return it;
}

iterator &iterator::operator--() {
    --m_index;
    return *this;
}

const iterator &iterator::operator--() const{
    --m_index;
    return *this;
}

iterator iterator::operator--(int) {
    iterator it(m_sequenceReference, m_index--);
    return it;
}

const iterator iterator::operator--(int) const{
    iterator it(m_sequenceReference, m_index--);
    return it;
}

void swap(iterator& lhs, iterator& rhs) {
    Nucleotide tmp(lhs[lhs.m_index]);

    lhs[lhs.m_index] = rhs[rhs.m_index];
    lhs[lhs.m_index] = tmp;
}

bool operator==(const iterator& it1, const iterator& it2) {
    return (& it1.m_sequenceReference) == (& it2.m_sequenceReference) && (it1.m_index == it2.m_index) ||
            (it1.m_index > it1.m_sequenceReference.size() && it2.m_index > it2.m_sequenceReference.size());
}

bool operator!=(const iterator& it1, const iterator& it2) {
    return !(it1 == it2);
}

const iterator operator+(const iterator& it, size_t index) {
    return iterator(it.m_sequenceReference, it.m_index + index);
}

iterator operator+(iterator& it, size_t index) {
    return iterator(it.m_sequenceReference, it.m_index + index);
}

const iterator operator+(size_t index, const iterator& it) {
    return iterator(it.m_sequenceReference, it.m_index + index);
}

iterator operator+(size_t index, iterator& it) {
    return iterator(it.m_sequenceReference, it.m_index + index);
}

iterator &iterator::operator+=(size_t index) {
    m_index += index;
    return *this;
}

const iterator &iterator::operator+=(size_t index) const {
    m_index += index;
    return *this;
}

iterator &iterator::operator-=(size_t index) {
    m_index -= index;
    return *this;
}

const iterator &iterator::operator-=(size_t index) const {
    m_index -= index;
    return *this;
}

const iterator operator-(const iterator& it, size_t index) {
    return iterator(it.m_sequenceReference, it.m_index+index);
}

size_t operator-(const iterator& it1, const iterator& it2) {
    return it1.m_index - it2.m_index;
}

Nucleotide &iterator::operator[](size_t index) {
    if(m_index + index > m_sequenceReference.size()) { throw std::exception(); }

    return m_sequenceReference[m_index];
}

const Nucleotide &iterator::operator[](size_t index) const {
    if(m_index + index > m_sequenceReference.size()) { throw std::exception(); }

    return m_sequenceReference[m_index + index];
}
