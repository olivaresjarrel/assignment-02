/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Jarrel Olivares <olivares.jarrel@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
 * Implements `buffer.h`.
 */

#include <iostream>

#include "buffer.h"

typedef unsigned int  uint; 

// ----------------------------------------------------------------------------

		Buffer::Buffer(unsigned int size_x, unsigned int size_y)
				: size_x(size_x), size_y(size_y)
			{
				data_ = new char[size_x*size_y];
				for (unsigned int i = 0; i < size_x * size_y; i++)
					{
						data_[i] = ' ';
					}
			}
        /**
         * The constructor.
         *
         * Must initialize `size_x` and `size_y`, and allocate memory for (and
         * initialize) `data_`.
         *
         * Notes:
         * - Since `size_x` and `size_y` are constant, they must be initialized
         *   in the initialization list, rather than set in the constructor
         *   body.
         * - You may assume that the dynamic memory allocation succeeds.
         */

		Buffer::~Buffer()
			{
				delete[] data_;
			}
        /**
         * The destructor.
         *
         * Must free the memory that the constructor allocated to `data_`.
         */


		char Buffer::get(unsigned int x, unsigned int y) const
			{
				return data_[ y * size_x + x ];
			}
        /**
         * Return the character at `data_[ y * size_x + x ]`.
         *
         * If `x` or `y` is out of bounds, should write
         * ```
         * "ERROR: `Buffer::get`: index out of bounds\n"
         * ```
         * to `cerr` and `exit(1)`.
		 * cerr << "something"
         */

        void Buffer::set(unsigned int x, unsigned int y, char c)
			{
				data_[y * size_x + x] = c;
			}
        /**
         * Set the character at `data_[ y * size_x + x ]` to `c`.
         *
         * If `x` or `y` is out of bounds, should write
         * ```
         * "ERROR: `Buffer::set`: index out of bounds\n"
         * ```
         * to `cerr` and `exit(1)`.
         */

		void Buffer::set(unsigned int pos_x, unsigned int pos_y, std::string s)
			{
				uint original_x = x;
				uint original_y = y;

				for (int i = 0; i < s.length(); i++)
				{
					if (s[i] == '\n'_)
					{
						y++;
						x = original_x;
					}
					else
					{
						set (x, y , s[i]);
						x++
					}
				}
			}
        /**
         * Overlay `s` onto `data_`.
         *
         * For example, if this buffer is representing an array that looks like
         * ```
         * *******
         * *******
         * *******
         * *******
         * *******
         * ```
         * and we call `set(1, 2, "hello\nworld")`, the buffer's contents
         * should now be
         * ```
         * *******
         * *******
         * *hello*
         * *world*
         * *******
         * ```
         *
         * Notes:
         * - This function may call the other `set` (which takes a `char` as
         *   its last argument), if you like.  In that case, you may leave the
         *   index error checking to the other `set`.  Otherwise, you should
         *   have checks in this function to make sure you're not putting
         *   characters where they don't belong.
         * - This function will be useful when implementing the `Shape` class.
         * - If you can't think of a way to do this, see
         *   `hint--implementation-of-Buffer-set.md`.
         */


        void Buffer::draw() const
			{
				for (uint y = 0; y < size_y; y++)
				{
					std::cout << get(x, y);
				}
				std::cout << std::endl;
			}
        /**
         * Output the contents of the buffer to `cout`.
         */


        void Buffer::clear()
			{
				for (uint y = 0; y < size_y; y++)
				{
					for (uint x = 0; x < size_x; x++)
					{
						data_[y * size_x + x] = ' ';
					}
				}
			}
        /**
         * Set each element `data_` to ' '.
         */