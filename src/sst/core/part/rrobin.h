// Copyright 2009-2017 Sandia Corporation. Under the terms
// of Contract DE-AC04-94AL85000 with Sandia Corporation, the U.S.
// Government retains certain rights in this software.
// 
// Copyright (c) 2009-2017, Sandia Corporation
// All rights reserved.
// 
// This file is part of the SST software package. For license
// information, see the LICENSE file in the top level directory of the
// distribution.
#ifndef SST_CORE_PART_RROBIN_H
#define SST_CORE_PART_RROBIN_H

#include <sst/core/part/sstpart.h>
#include <sst/core/elementinfo.h>

namespace SST {
namespace Partition {

class SSTRoundRobinPartition : public SST::Partition::SSTPartitioner {

private:
    RankInfo world_size;

public:
    SSTRoundRobinPartition(RankInfo world_size, RankInfo my_rank, int verbosity);
    
    /**
       Performs a partition of an SST simulation configuration
       \param graph The simulation configuration to partition
    */
	void performPartition(PartitionGraph* graph) override;

    bool requiresConfigGraph() override { return false; }
    bool spawnOnAllRanks() override { return false; }
    
        
    SST_ELI_REGISTER_PARTITIONER(SSTRoundRobinPartition,"sst","roundrobin","Partitions components using a simple round robin scheme based on ComponentID.  Sequential IDs will be placed on different ranks.")

    SST_ELI_DOCUMENT_VERSION(1,0,0)
};

} // namespace Partition
} //namespace SST
#endif //SST_CORE_PART_RROBIN_H