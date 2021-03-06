/**
 *  @file monoXEntropy.h
 *  @brief Derived class to handle filtering mode 2: monolingual cross-entropy
 *  @author Anthony Rousseau
 *  @version 2.0.0
 *  @date 18 March 2016
 */

/*  This file is part of the cross-entropy tool for data selection (XenC)
 *  aimed at speech recognition and statistical machine translation.
 *
 *  Copyright 2013-2016, Anthony Rousseau, LIUM, University of Le Mans, France
 *
 *  Development of the XenC tool has been partially funded by the
 *  European Commission under the MateCat project.
 *
 *  The XenC tool is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU Lesser General Public License version 3 as
 *  published by the Free Software Foundation
 *
 *  This library is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library; if not, write to the Free Software Foundation,
 *  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef MONOXENTROPY_H_
#define MONOXENTROPY_H_

#include <boost/make_shared.hpp>

#include "../mode.h"       //!< Inherit boost::filesystem from here
#include "../utils/StaticData.h"    //!< Inherit boost::shared_ptr from here

using namespace boost;

/**
 *  @class MonoXEntropy
 *  @brief Filtering mode 2: monolingual cross-entropy
 *
 *  This class derived from Mode handles the second filtering mode:
 *  monolingual cross-entropy
 */
class MonoXEntropy : public Mode {
public:
    /**
     *  @fn MonoXEntropy ()
     *  @brief Default constructor
     */
    MonoXEntropy();
    
    /**
     *  @fn ~MonoXEntropy ()
     *  @brief Default destructor
     */
    ~MonoXEntropy();
    
    /**
     *  @fn int launch ()
     *  @brief Function in charge of launching the filtering mode
     *
     *  @return 0 if the filtering succeeds
     */
    int launch();
};

#endif
