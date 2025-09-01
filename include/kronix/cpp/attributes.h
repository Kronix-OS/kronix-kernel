#pragma once

#undef KRONIX_NORETURN
/**
 * @def KRONIX_NORETURN
 * @brief Attribute to specify that a function is not expected to return
 */
#define KRONIX_NORETURN [[__noreturn__]]

#undef KRONIX_KEEP
/**
 * @def KRONIX_KEEP
 * @brief Attribute to specify that a symbol should be kept regardless if it appears in source-code
 * otherwise or not
 */
#define KRONIX_KEEP [[__gnu__::__used__]]

#undef KRONIX_UNUSED
/**
 * @def KRONIX_UNUSED
 * @brief Attribute to specify that a symbol might be unused, and that it's expected
 */
#define KRONIX_UNUSED [[__maybe_unused__]]

#undef KRONIX_SECTION
/**
 * @def KRONIX_SECTION(section)
 * @brief Attribute to specify that a symbol should reside in the given section
 */
#define KRONIX_SECTION(section) [[__gnu__::__section__(section)]]

#undef KRONIX_NOTHROW
/**
 * @def KRONIX_NOTHROW
 * @brief Attribute to specify that a function does not throw any exception
 */
#define KRONIX_NOTHROW [[__gnu__::__nothrow__]]
