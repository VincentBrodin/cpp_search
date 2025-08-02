#ifndef UTILS_H
#define UTILS_H

namespace utils {
template <typename T>
bool in_range(T min, T value, T max) {
	return min <= value && value <= max;
};
}  // namespace utils
#endif /* UTILS_H */
