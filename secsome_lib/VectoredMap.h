#pragma once

#include <vector>

namespace secsome::structure
{
	template <typename TKey, typename TValue>
	class VectoredMap {
	private:
		using container_t = std::vector<std::pair<TKey, TValue>>;
	public:
		using iterator = container_t::iterator;
		using const_iterator = container_t::const_iterator;

		[[nodiscard]] iterator begin() noexcept
		{
			return values.begin();
		}

		[[nodiscard]] const_iterator begin() const noexcept
		{
			return values.begin();
		}

		[[nodiscard]] iterator end() noexcept
		{
			return values.end();
		}

		[[nodiscard]] const_iterator end() const noexcept
		{
			return values.end();
		}

		TValue& operator[] (const TKey& key) {
			if (auto pValue = this->find(key)) {
				return *pValue;
			}
			return this->insert_unchecked(key, TValue());
		}

		TValue* find(const TKey& key) {
			auto pValue = static_cast<const VectoredMap*>(this)->find(key);
			return const_cast<TValue*>(pValue);
		}

		const TValue* find(const TKey& key) const {
			auto it = this->get_iterator(key);
			if (it != this->values.end()) {
				return &it->second;
			}
			return nullptr;
		}

		TValue get_or_default(const TKey& key) const {
			if (auto pValue = this->find(key)) {
				return *pValue;
			}
			return TValue();
		}

		TValue get_or_default(const TKey& key, TValue def) const {
			if (auto pValue = this->find(key)) {
				return *pValue;
			}
			return def;
		}

		bool erase(const TKey& key) {
			auto it = this->get_iterator(key);
			if (it != this->values.end()) {
				this->values.erase(it);
				return true;
			}
			return false;
		}

		bool contains(const TKey& key) const {
			return this->get_iterator(key) != this->values.end();
		}

		bool insert(const TKey& key, TValue value) {
			if (!this->find(key)) {
				this->insert_unchecked(key, std::move(value));
				return true;
			}
			return false;
		}

		size_t size() const {
			return this->values.size();
		}

		bool empty() const {
			return this->values.empty();
		}

		void clear() {
			this->values.clear();
		}

		typename container_t::const_iterator get_iterator(const TKey& key) const {
			return std::find_if(this->values.begin(), this->values.end(), [&](const container_t::value_type& item) {
				return item.first == key;
				});
		}

		TValue& insert_unchecked(const TKey& key, TValue value) {
			this->values.emplace_back(key, std::move(value));
			return this->values.back().second;
		}

	private:
		container_t values;
	};

}