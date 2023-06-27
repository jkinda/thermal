#include "Darcy.h"

registerMooseObject("ThermalApp", Darcy);

InputParameters
Darcy::validParams()
{
  InputParameters params = ADKernelGrad::validParams();
  params.addClassDescription("Compute the diffusion term for Darcy pressure ($p$) equation: "
                             "$-\\nabla \\cdot \\frac{\\mathbf{K}}{\\mu} \\nabla p = 0$");

  return params;
}

Darcy::Darcy(const InputParameters & parameters)
  : ADKernelGrad(parameters),

    // Set the coefficients for the pressure kernel
    _permeability(0.8451e-09),
    _viscosity(7.98e-04)
{
}

ADRealVectorValue
Darcy::precomputeQpResidual()
{
  return (_permeability / _viscosity) * _grad_u[_qp];
}