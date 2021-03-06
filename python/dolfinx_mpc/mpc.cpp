// Copyright (C) 2020 Jørgen S. Dokken
//
// This file is part of DOLFINX-MPC
//
// SPDX-License-Identifier:    LGPL-3.0-or-later

#include <Eigen/Dense>
#include <dolfinx/common/IndexMap.h>
#include <dolfinx/fem/Form.h>
#include <dolfinx/function/FunctionSpace.h>
#include <dolfinx_mpc/MultiPointConstraint.h>
#include <dolfinx_mpc/utils.h>
#include <memory>
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

namespace dolfinx_mpc_wrappers
{
void mpc(py::module& m)
{
  // dolfinx_mpc::MultiPointConstraint
  py::class_<dolfinx_mpc::MultiPointConstraint,
             std::shared_ptr<dolfinx_mpc::MultiPointConstraint>>
      multipointconstraint(m, "MultiPointConstraint",
                           "Object for representing multi-point constraints");
  multipointconstraint
      .def(py::init<std::shared_ptr<const dolfinx::function::FunctionSpace>,
                    Eigen::Array<std::int64_t, Eigen::Dynamic, 1>,
                    Eigen::Array<std::int64_t, Eigen::Dynamic, 1>,
                    Eigen::Array<double, Eigen::Dynamic, 1>,
                    Eigen::Array<std::int32_t, Eigen::Dynamic, 1>>())
      .def("slave_cells", &dolfinx_mpc::MultiPointConstraint::slave_cells)
      .def("slave_cell_to_dofs",
           &dolfinx_mpc::MultiPointConstraint::slave_cell_to_dofs)
      .def("coefficients", &dolfinx_mpc::MultiPointConstraint::coefficients)
      .def("slaves", &dolfinx_mpc::MultiPointConstraint::slaves)
      .def("index_map", &dolfinx_mpc::MultiPointConstraint::index_map)
      .def("masters_local", &dolfinx_mpc::MultiPointConstraint::masters_local)
      .def("create_sparsity_pattern",
           &dolfinx_mpc::MultiPointConstraint::create_sparsity_pattern)
      .def("mpc_dofmap", &dolfinx_mpc::MultiPointConstraint::mpc_dofmap);
  m.def("get_basis_functions", &dolfinx_mpc::get_basis_functions);
}
} // namespace dolfinx_mpc_wrappers
