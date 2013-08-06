/*
 *  Copyright 2011-2013 Maxim Milakov
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include "layer_configuration_specific.h"
#include "output_neuron_value_set.h"
#include "neuron_data_type.h"

namespace nnforge
{
	class supervised_data_reader
	{
	public:
		virtual ~supervised_data_reader();

		// The method should return true in case entry is read and false if there is no more entries available (and no entry is read in this case)
		// If any parameter is null the method should just discard corresponding data
		virtual bool read(
			void * input_elems,
			float * output_elems) = 0;

		virtual void reset() = 0;

		virtual layer_configuration_specific get_input_configuration() const = 0;

		virtual layer_configuration_specific get_output_configuration() const = 0;

		virtual unsigned int get_entry_count() const = 0;

		virtual neuron_data_type::input_type get_input_type() const = 0;

		size_t get_input_neuron_elem_size() const;

		output_neuron_value_set_smart_ptr get_output_neuron_value_set(unsigned int sample_count);

	protected:
		supervised_data_reader();

	private:
		supervised_data_reader(const supervised_data_reader&);
		supervised_data_reader& operator =(const supervised_data_reader&);
	};

	typedef std::tr1::shared_ptr<supervised_data_reader> supervised_data_reader_smart_ptr;
}