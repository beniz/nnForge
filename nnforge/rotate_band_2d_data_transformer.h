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

#include "data_transformer.h"

#include "rnd.h"

#include <memory>

namespace nnforge
{
	class rotate_band_2d_data_transformer : public data_transformer
	{
	public:
		rotate_band_2d_data_transformer(
			unsigned int max_absolute_band_rotation_x,
			unsigned int max_absolute_band_rotation_y);

		virtual ~rotate_band_2d_data_transformer();

		virtual void transform(
			const void * data,
			void * data_transformed,
			neuron_data_type::input_type type,
			const layer_configuration_specific& original_config,
			unsigned int sample_id);
			
	protected:
		random_generator generator;

		std::uniform_int_distribution<int> rotate_band_x_distribution;
		std::uniform_int_distribution<int> rotate_band_y_distribution;
	};
}
