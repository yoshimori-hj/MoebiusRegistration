cmake_minimum_required(VERSION 3.20)

project(MoebiusRegistration VERSION 2.52 LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Whether build shared libs" OFF)

find_package(PkgConfig REQUIRED)
pkg_check_modules(FFTW3 REQUIRED fftw3 fftw3f)

option(ENABLE_OPENMP "Enable OpenMP" OFF)
if(ENABLE_OPENMP)
  find_package(OpenMP REQUIRED)
  set(OPENMP_TARGET "OpenMP::OpenMP_CXX")
else()
  unset(OPENMP_TARGET)
endif()

option(WITH_SYSTEM_EIGEN3 "Use system installed Eigen3" ON)
if(WITH_SYSTEM_EIGEN3)
  find_package(Eigen3 REQUIRED)
endif()

set(BASEDIR "${CMAKE_CURRENT_SOURCE_DIR}")

if(TARGET Eigen3::Eigen)
  set(EIGEN "Eigen3::Eigen")
else()
  set(EIGEN_INCDIR "${BASEDIR}/Eigen3")
  add_library(MoebiousRegistration-Local-Eigen3 INTERFACE)
  target_include_directories(MoebiousRegistration-Local-Eigen3
                             INTERFACE "$<BUILD_INTERFACE:${EIGEN_INCDIR}>")
  set(EIGEN MoebiousRegistration-Local-Eigen3)
endif()

# SO(3) Fourier Transform
set(SOFTDIR "${BASEDIR}/SOFT1.0")

add_library(
  SOFT
  ${SOFTDIR}/FFTcode.cpp
  ${SOFTDIR}/FST_semi_memo.cpp
  ${SOFTDIR}/FST_semi_memo_fftw.cpp
  ${SOFTDIR}/OURmods.cpp
  ${SOFTDIR}/OURperms.cpp
  ${SOFTDIR}/cospmls.cpp
  ${SOFTDIR}/csecond.cpp
  ${SOFTDIR}/fft_grids.cpp
  ${SOFTDIR}/fft_grids_so3.cpp
  ${SOFTDIR}/indextables.cpp
  ${SOFTDIR}/makeWigner.cpp
  ${SOFTDIR}/naive_synthesis.cpp
  ${SOFTDIR}/newFCT.cpp
  ${SOFTDIR}/oddweights.cpp
  ${SOFTDIR}/permroots.cpp
  ${SOFTDIR}/primitive.cpp
  ${SOFTDIR}/primitive_FST.cpp
  ${SOFTDIR}/rotate_so3.cpp
  ${SOFTDIR}/rotate_so3_mem.cpp
  ${SOFTDIR}/seminaive.cpp
  ${SOFTDIR}/seminaive_fftw.cpp
  ${SOFTDIR}/so3_correlate_fftw.cpp
  ${SOFTDIR}/so3_correlate_sym.cpp
  ${SOFTDIR}/soft.cpp
  ${SOFTDIR}/soft_fftw.cpp
  ${SOFTDIR}/soft_fftw_pc.cpp
  ${SOFTDIR}/soft_fftw_wo.cpp
  ${SOFTDIR}/soft_sym.cpp
  ${SOFTDIR}/utils_so3.cpp
  ${SOFTDIR}/utils_vec_cx.cpp
  ${SOFTDIR}/weights.cpp
  ${SOFTDIR}/wignerTransforms.cpp
  ${SOFTDIR}/wignerTransforms_fftw.cpp
  ${SOFTDIR}/wignerTransforms_sym.cpp)

get_target_property(SOFT_TYPE SOFT TYPE)
if(SOFT_TYPE STREQUAL "SHARED_LIBRARY")
  target_compile_definitions(SOFT PRIVATE SOFT_EXPORT)
  target_compile_definitions(SOFT INTERFACE SOFT_IMPORT)
endif()

set_target_properties(SOFT PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED
                                                      FALSE)
target_link_libraries(SOFT PUBLIC ${FFTW3_LIBRARIES})

target_include_directories(
  SOFT
  PRIVATE ${SOFTDIR}
  INTERFACE $<BUILD_INTERFACE:${SOFTDIR}>)

# Misha
set(MISHA_INCDIR "${BASEDIR}/Include")
add_library(Misha INTERFACE)
target_include_directories(Misha INTERFACE "$<BUILD_INTERFACE:${MISHA_INCDIR}>")
target_link_libraries(Misha INTERFACE SOFT ${EIGEN} ${OPENMP_TARGET})

# Tools
set(REGISTER_DIR "${BASEDIR}/Register")
add_executable(moebius-register ${REGISTER_DIR}/Register.cpp)
target_link_libraries(moebius-register Misha)

set(PARAMETRIZATION_DIR "${BASEDIR}/Parametrization")
add_executable(moebius-parametrization
               ${PARAMETRIZATION_DIR}/Parametrization.cpp)
target_link_libraries(moebius-parametrization Misha)

set(SPHERE_MAP_DIR "${BASEDIR}/SphereMap")
add_executable(moebius-sphere-map ${SPHERE_MAP_DIR}/SphereMap.cpp)
target_link_libraries(moebius-sphere-map Misha)
