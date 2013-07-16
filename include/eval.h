/*
 * This file is part of the cross-entropy tool for data selection (XenC)
 * aimed at speech recognition and statistical machine translation.
 *
 * Copyright 2013, Anthony Rousseau, LIUM, University of Le Mans, France
 *
 * The XenC tool is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * $Id: eval.h, v 1.0 PUBLIC RELEASE 2013/07/16 rousseau Exp $
 */

/*
 *  Class to handle the evaluation system
 *  Uses threads extensively
 *  (watch your memory usage since
 *  SRILM seems to extremely eat it up)
 */

#ifndef EVAL_H_
#define EVAL_H_

#include <boost/regex.hpp>

#include "utils/common.h"
#include "utils/threadpool.hpp"

#include "corpus.h"
#include "xenoption.h"
#include "XenLMsri.h"
#include "ppl.h"
#include "xenresult.h"

class StaticData;

using namespace boost::threadpool;
using namespace boost;

typedef map<int, double, greater<int> > EvalMap;    // Map with inverted sorting order

void taskEval(int, shared_ptr<XenResult>, shared_ptr<XenVocab>, shared_ptr<Corpus>, shared_ptr<EvalMap>);      // Thread-safe function for parallel eval

class Eval {
    public:
        Eval();
        Eval(string);
        ~Eval();
        // -------------------
        void doEval(int, int);
        void doBP();
        EvalMap getDist() const;
        
    
    private:
        shared_ptr<EvalMap> ptrDist;
};

#endif