/**
 * @file test_state.cpp
 * @author Maximilien Naveau (maximilien.naveau@gmail.com)
 * @license License BSD-2-Clause
 * @copyright Copyright (c) 2019, New York University, Max Planck Gesellshaft and LAAS.
 * @date 2019-06-18
 */

#include <boost/test/included/unit_test.hpp>
#include <boost/bind.hpp>
#include "crocoddyl/core/state-base.hpp"
#include "crocoddyl/core/states/state-euclidean.hpp"
#include "crocoddyl/core/states/state-unicycle.hpp"

using namespace boost::unit_test;

//____________________________________________________________________________//

void free_test_function( int i, int j )
{
    BOOST_CHECK( true /* test assertion */ );
}

void test_state_dimension(crocoddyl::StateAbstract& state, int Nx)
{
  BOOST_CHECK(state.zero().size() == Nx);
  BOOST_CHECK(state.rand().size() == Nx);
}

    // def test_state_dimension(self):
    //     # Checking the dimension of zero and random states
    //     self.assertEqual(self.STATE.zero().shape, (self.NX, ), "Wrong dimension of zero state.")
    //     self.assertEqual(self.STATE.rand().shape, (self.NX, ), "Wrong dimension of random state.")

    // def test_integrate_against_difference(self):
    //     # Generating random states
    //     x1 = self.STATE.rand()
    //     x2 = self.STATE.rand()

    //     # Computing x2 by integrating its difference
    //     dx = self.STATE.diff(x1, x2)
    //     x2i = self.STATE.integrate(x1, dx)

    //     dxi = self.STATE.diff(x2i, x2)

    //     # Checking that both states agree
    //     self.assertTrue(np.allclose(dxi, np.zeros(self.STATE.ndx), atol=1e-9),
    //                     "Integrate function doesn't agree with difference rule.")

    // def test_difference_against_integrate(self):
    //     # Generating random states
    //     x1 = self.STATE.rand()
    //     dx = np.random.rand(self.STATE.ndx)

    //     # Computing dx by differentiation its integrate
    //     dxd = self.STATE.diff(x1, self.STATE.integrate(x1, dx))

    //     # Checking that both states agree
    //     self.assertTrue(np.allclose(dxd, dx, atol=1e-9), "Difference function doesn't agree with integrate rule.")

    // def test_Jdiff_against_numdiff(self):
    //     # Generating random values for the initial and terminal states
    //     x1 = self.STATE.rand()
    //     x2 = self.STATE.rand()

    //     # Computing the partial derivatives of the difference function
    //     J1, J2 = self.STATE.Jdiff(x1, x2)
    //     Jnum1, Jnum2 = self.STATE_NUMDIFF.Jdiff(x1, x2)

    //     # Checking the partial derivatives against NumDiff
    //     # The previous tolerance was 10*disturbance
    //     tol = self.NUMDIFF_MOD * self.STATE_NUMDIFF.disturbance
    //     assertNumDiff(J1, Jnum1, tol)
    //     assertNumDiff(J2, Jnum2, tol)

    // def test_Jintegrate_against_numdiff(self):
    //     # Generating random values for the initial state and its rate of change
    //     x = self.STATE.rand()
    //     vx = np.random.rand(self.STATE.ndx)

    //     # Computing the partial derivatives of the integrate function
    //     J1, J2 = self.STATE.Jintegrate(x, vx)
    //     Jnum1, Jnum2 = self.STATE_NUMDIFF.Jintegrate(x, vx)

    //     # Checking the partial derivatives against NumDiff
    //     # The previous tolerance was 10*disturbance
    //     tol = self.NUMDIFF_MOD * self.STATE_NUMDIFF.disturbance
    //     assertNumDiff(J1, Jnum1, tol)
    //     assertNumDiff(J2, Jnum2, tol)

    // def test_Jdiff_and_Jintegrate_are_inverses(self):
    //     # Generating random states
    //     x1 = self.STATE.rand()
    //     dx = np.random.rand(self.STATE.ndx)
    //     x2 = self.STATE.integrate(x1, dx)

    //     # Computing the partial derivatives of the integrate and difference function
    //     Jx, Jdx = self.STATE.Jintegrate(x1, dx)
    //     J1, J2 = self.STATE.Jdiff(x1, x2)

    //     # Checking that Jdiff and Jintegrate are inverses
    //     dX_dDX = Jdx
    //     dDX_dX = J2
    //     assertNumDiff(dX_dDX, np.linalg.inv(dDX_dX), 1e-9)

    // def test_velocity_from_Jintegrate_Jdiff(self):
    //     # Generating random states
    //     x1 = self.STATE.rand()
    //     dx = np.random.rand(self.STATE.ndx)
    //     x2 = self.STATE.integrate(x1, dx)
    //     eps = np.random.rand(self.STATE.ndx)
    //     h = 1e-8

    //     # Computing the partial derivatives of the integrate and difference function
    //     Jx, Jdx = self.STATE.Jintegrate(x1, dx)
    //     J1, J2 = self.STATE.Jdiff(x1, x2)

    //     # Checking that computed velocity from Jintegrate
    //     dX_dDX = Jdx
    //     x2eps = self.STATE.integrate(x1, dx + eps * h)
    //     self.assertTrue(np.allclose(np.dot(dX_dDX, eps), self.STATE.diff(x2, x2eps) / h, atol=1e-3),
    //                     "Velocity computed from Jintegrate is wrong.")

    //     # Checking the velocity computed from Jdiff
    //     x = self.STATE.rand()
    //     dx = self.STATE.diff(x1, x)
    //     x2i = self.STATE.integrate(x, eps * h)
    //     dxi = self.STATE.diff(x1, x2i)
    //     J1, J2 = self.STATE.Jdiff(x1, x)
    //     self.assertTrue(np.allclose(np.dot(J2, eps), (-dx + dxi) / h, atol=1e-3),
    //                     "Velocity computed from Jdiff is wrong.")


//____________________________________________________________________________//

bool
init_function()
{
    int nx = 10;
    framework::master_test_suite().add(BOOST_TEST_CASE(
      boost::bind(&test_state_dimension, crocoddyl::StateVector(nx), nx) ));

    return true;
}

//____________________________________________________________________________//

int
main( int argc, char* argv[] )
{
    return ::boost::unit_test::unit_test_main( &init_function, argc, argv );
}
