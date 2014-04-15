// Copyright 2009-2014 Sandia Corporation. Under the terms
// of Contract DE-AC04-94AL85000 with Sandia Corporation, the U.S.
// Government retains certain rights in this software.
//
// Copyright (c) 2009-2014, Sandia Corporation
// All rights reserved.
//
// This file is part of the SST software package. For license
// information, see the LICENSE file in the top level directory of the
// distribution.


#ifndef SST_CORE_PART_LINEAR
#define SST_CORE_PART_LINEAR

#include <sst/core/part/sstpart.h>
#include <sst/core/output.h>

using namespace SST;
using namespace SST::Partition;

namespace SST {
namespace Partition {

/**
Performs a linear partition scheme of an SST simulation configuration. In this
scheme a list of components (supplied as a graph) are grouped by slicing the list
into approximately equal parts. A "part" is generated for each MPI rank performing
the simulation. This means Components with sequential ids will be placed close together.
In general this scheme provides a very effective partition for most parallel
simulations which generate man similar components of interest close together in the input
Python configuration. It is also very fast to compute a linear partiton scheme. For
more aggressive partition schemes users should try either a simple or Zoltan-based
partitioner.
*/
class SSTLinearPartition : public SST::Partition::SSTPartitioner {

	public:
		/**
			Creates a new linear partition scheme.
			\param mpiRankCount Number of MPI ranks in the simulation
			\param verbosity The level of information to output
		*/
		SSTLinearPartition(int mpiRankCount, int verbosity);

		/**
			Performs a partition of an SST simulation configuration
			\param graph The simulation configuration to partition
		*/
		void performPartition(ConfigGraph* graph);

	protected:
		int rankcount;
		Output* partOutput;

};

}
}

#endif
