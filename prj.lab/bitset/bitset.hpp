#ifndef BITSET_20241803
#define BITSET_20241803
#include <iostream>
#include <vector>
class BitSet {
public:
		class BiA {
		private:
			BitSet& bs_;
			std::int32_t id_;
		public:
			BiA() = delete;
			BiA(BitSet& x, const std::int32_t ind) : bs_(x), id_(ind) {}
			~BiA() = default;
			void operator=(const bool v) {
				bs_.Set(id_, v);
			}
		};
	BitSet() = default;
	BitSet(const BitSet& copy);
	BitSet(const int32_t& size);
	BitSet(BitSet&& copy) noexcept;
	
	BitSet& operator=(const BitSet& copy) ;
	BitSet& operator=(BitSet&& copy) noexcept;
	BitSet& operator&=(const BitSet& val);
	BitSet& operator|=(const BitSet& val);
	BitSet& operator^=(const BitSet& val);
	void operator~();
	BiA operator[](const int32_t& id);
	[[nodiscard]] bool operator==(const BitSet& val);
	[[nodiscard]] bool operator!=(const BitSet& val);



	int32_t Size() {};
	void Resize(const int32_t& size);
	bool Get(const int32_t& id) const;
	void Set(const int32_t& id, const bool& val);

		
	private:
		std::vector<uint32_t> data_;
		int32_t  size_ = 0;
};
BitSet operator&(const BitSet& lhs, const BitSet& rhs);
BitSet operator|(const BitSet& lhs, const BitSet& rhs);
BitSet operator^(const BitSet& lhs, const BitSet& rhs);
#endif // !BITSET_20241803
