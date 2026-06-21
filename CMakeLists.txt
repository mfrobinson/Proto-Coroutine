cmake_minimum_required(VERSION 3.10)
set(LIBRARY_NAME ProtoCoroutine)
project(${LIBRARY_NAME} VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

# Set the declaration files
set(
	DECLARATIONS
	StackableManagedTask.h
	StackableManagedTaskAwaiter.h
	StackableManagedTaskAwaiterBase.h
	StackablePromiseWithResult.h
	StackableTaskBase.h
	StackableUnmanagedTask.h
	StackableUnmanagedTaskAwaiter.h
)
set(
	PLATFORM_DEPENDENT_DECLARATIONS
)

# Set the include files
set(
	INCLUDES
	StackableManagedPromise.h
	StackableManagedPromiseBase.h
	StackableManagedPromiseBaseConcept.h
	StackableManagedPromiseFinalAwaiter.h
	StackableManagedTask.h
	StackableManagedTaskAwaiter.h
	StackableManagedTaskAwaiterBase.h
	StackablePromise.h
	StackablePromiseConcept.h
	StackablePromiseWithResult.h
	StackableTaskBase.h
	StackableUnmanagedPromise.h
	StackableUnmanagedPromiseBase.h
	StackableUnmanagedPromiseBaseConcept.h
	StackableUnmanagedPromiseFinalAwaiter.h
	StackableUnmanagedTask.h
	StackableUnmanagedTaskAwaiter.h
)
set(
	PLATFORM_DEPENDENT_INCLUDES
)

# Set the source files
set(
	SOURCES
	StackableManagedPromiseBase.cpp
	StackableManagedPromiseFinalAwaiter.cpp
	StackablePromise.cpp
	StackableUnmanagedPromiseBase.cpp
	StackableUnmanagedPromiseFinalAwaiter.cpp
)
set(
	PLATFORM_DEPENDENT_SOURCES
)

# Append the appropriate platform includes and declarations to the generic includes and declarations
if (WIN32)
	set(PLATFORM_PREPEND "Windows/")
elseif(APPLE)
	set(PLATFORM_PREPEND "Apple/")
elseif (UNIX)
	set(PLATFORM_PREPEND "Unix/")
endif()

# Point the platform dependent files to the right platform directories
list(TRANSFORM PLATFORM_DEPENDENT_DECLARATIONS PREPEND ${PLATFORM_PREPEND})
list(TRANSFORM PLATFORM_DEPENDENT_INCLUDES PREPEND ${PLATFORM_PREPEND})
list(TRANSFORM PLATFORM_DEPENDENT_SOURCES PREPEND ${PLATFORM_PREPEND})

# Merge the platform dependent and independent files together
list(APPEND DECLARATIONS ${PLATFORM_DEPENDENT_DECLARATIONS})
list(APPEND INCLUDES ${PLATFORM_DEPENDENT_INCLUDES})
list(APPEND SOURCES ${PLATFORM_DEPENDENT_SOURCES})

# Prepend the appropriate folder structure specific to this project (proto::net)
list(TRANSFORM INCLUDES PREPEND "Proto/Coroutine/")
list(TRANSFORM DECLARATIONS PREPEND "Declarations/Proto/Coroutine/")
list(TRANSFORM SOURCES PREPEND "Src/Proto/Coroutine/")

# Merge the includes and declarations together since they are both to be includes
list(APPEND INCLUDES ${DECLARATIONS})


add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_sources (${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
	$<INSTALL_INTERFACE:Include>
)
target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<INSTALL_INTERFACE:>
)