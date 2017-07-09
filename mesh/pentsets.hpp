// Copyright (c) 2010, Lawrence Livermore National Security, LLC. Produced at
// the Lawrence Livermore National Laboratory. LLNL-CODE-443211. All Rights
// reserved. See file COPYRIGHT for details.
//
// This file is part of the MFEM library. For more information and source code
// availability see http://mfem.org.
//
// MFEM is free software; you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License (as published by the Free
// Software Foundation) version 2.1 dated February 1999.

#ifndef MFEM_PAR_ENTITY_SETS
#define MFEM_PAR_ENTITY_SETS

#include "../config/config.hpp"

#ifdef MFEM_USE_MPI

#include "entsets.hpp"

namespace mfem
{

class ParMesh;

class ParEntitySets : public EntitySets
{
   friend class ParMesh;

public:
   ParEntitySets(const ParEntitySets & ent_sets);
   ParEntitySets(ParMesh & _mesh, const EntitySets & ent_sets, int * part,
                 const Array<int> & vert_global_local);

   virtual ~ParEntitySets();

   virtual void PrintSetInfo(std::ostream &output) const;

   inline ParMesh *GetParMesh() const { return pmesh_; }

private:

   void PrintEntitySetInfo(std::ostream & output, EntityType t,
                           const std::string & ent_name) const;

   ParMesh  * pmesh_;
   int        NRanks_;
   int        MyRank_;
};

class ParNCEntitySets : public NCEntitySets
{
public:
private:
};

} // namespace mfem

#endif // MFEM_USE_MPI

#endif // MFEM_PAR_ENTITY_SETS
