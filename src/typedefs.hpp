#ifndef TYPEDEFS_H_
# define TYPEDEFS_H_

# include <string>
# include <vector>
# include <map>
# include <memory>
# include <functional>

# define CALL_MEMBER_FN(object, func_ptr) ((object).*(func_ptr))

template <class T>
using Sptr		= std::shared_ptr<T>;
using t_vec_pair_string	= std::vector<std::pair<std::string, std::string>>;
using t_vec_string	= std::vector<std::string>;
using t_vec_string_num	= std::vector<std::pair<std::string, size_t>>;
using t_map_string_num	= std::map<std::string, int>;

#endif /* !TYPEDEFS_H_ */
