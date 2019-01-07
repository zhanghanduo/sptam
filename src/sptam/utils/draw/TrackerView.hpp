/**
 * This file is part of S-PTAM.
 *
 * Copyright (C) 2013-2017 Taihú Pire
 * Copyright (C) 2014-2017 Thomas Fischer
 * Copyright (C) 2016-2017 Gastón Castro
 * Copyright (C) 2017 Matias Nitsche
 * For more information see <https://github.com/lrse/sptam>
 *
 * S-PTAM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * S-PTAM is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with S-PTAM. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:  Taihú Pire
 *           Thomas Fischer
 *           Gastón Castro
 *           Matías Nitsche
 *
 * Laboratory of Robotics and Embedded Systems
 * Department of Computer Science
 * Faculty of Exact and Natural Sciences
 * University of Buenos Aires
 */

#pragma once

#include "../../Match.hpp"
#include "../../sptamParameters.hpp"
#include "../../Map.hpp"

namespace sptam
{

class TrackerView
{
  public:

    virtual ~TrackerView() {}

    /**
     * Visualize tracking data.
     * @param before_refine if true, feature detection grid and unmatched keypoints are also drawn
     */
    virtual void draw(const StereoFrame& frame, const sptam::Map::SharedMapPointList& filtered_points,
      const std::list<Match>& measurements, const Parameters& params, bool before_refine) = 0;

    virtual void draw_cross(const StereoFrame& frame, const sptam::Map::SharedMapPointList& filtered_points,
                      const std::list<Match>& measurements, const std::list<Match2D> match_measures,
                      const Parameters& params) = 0;

    virtual cv::Vec3b featureColor(const Measurement& meas) const = 0;
};

}
