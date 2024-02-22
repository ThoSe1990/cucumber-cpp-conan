#pragma once

#include <string>
#include <vector>

class box
{
 public:
  box() = default;

  void add_item(const std::string& item) { m_items.push_back(item); }
  void add_items(const std::string& item, std::size_t count)
  {
    for ([[maybe_unused]] int i = 0; i < count; i++)
    {
      add_item(item);
    }
  }
  [[nodiscard]] std::size_t items_count() const noexcept
  {
    return m_items.size();
  }

  void close() noexcept { m_is_open = false; }

 private:
  bool m_is_open{true};
  std::vector<std::string> m_items;
};