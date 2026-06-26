cmake_minimum_required(VERSION 3.10)
set(LIBRARY_NAME ProtoCoroutine)
project(${LIBRARY_NAME} VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

# Set the declaration files
set(
	DECLARATIONS
	# Stackable/
	Stackable/PromiseWithResult.h
	Stackable/TaskBase.h
	# Stackable/Managed/
	Stackable/Managed/Task.h
	Stackable/Managed/TaskAwaiter.h
	Stackable/Managed/TaskAwaiterBase.h
	# Stackable/Managed/Eager/
	Stackable/Managed/Eager/DefaultPromise.h
	Stackable/Managed/Eager/TaskAwaiterBase.h
	# Stackable/Managed/Lazy/
	Stackable/Managed/Lazy/DefaultPromise.h
	Stackable/Managed/Lazy/TaskAwaiterBase.h
	# Stackable/Unmanaged/Eager/
	Stackable/Unmanaged/Eager/DefaultPromise.h
	# Stackable/Unmanaged/Lazy/
	Stackable/Unmanaged/Lazy/DefaultPromise.h
)
set(
	PLATFORM_DEPENDENT_DECLARATIONS
)

# Set the include files
set(
	INCLUDES
	# Stackable/
	Stackable/Promise.h
	Stackable/PromiseConcept.h
	Stackable/PromiseWithResult.h
	Stackable/TaskBase.h
	# Stackable/Managed/
	Stackable/Managed/Promise.h
	Stackable/Managed/PromiseBase.h
	Stackable/Managed/PromiseBaseConcept.h
	Stackable/Managed/PromiseFinalAwaiter.h
	Stackable/Managed/Task.h
	Stackable/Managed/TaskAwaiter.h
	Stackable/Managed/TaskAwaiterBase.h
	# Stackable/Managed/Eager/
	Stackable/Managed/Eager/DefaultPromise.h
	Stackable/Managed/Eager/DefaultTask.h
	Stackable/Managed/Eager/Promise.h
	Stackable/Managed/Eager/PromiseBase.h
	Stackable/Managed/Eager/Task.h
	Stackable/Managed/Eager/TaskAwaiter.h
	Stackable/Managed/Eager/TaskAwaiterBase.h
	# Stackable/Managed/Lazy/
	Stackable/Managed/Lazy/DefaultPromise.h
	Stackable/Managed/Lazy/DefaultTask.h
	Stackable/Managed/Lazy/Promise.h
	Stackable/Managed/Lazy/PromiseBase.h
	Stackable/Managed/Lazy/Task.h
	Stackable/Managed/Lazy/TaskAwaiter.h
	Stackable/Managed/Lazy/TaskAwaiterBase.h
	# Stackable/Unmanaged/
	Stackable/Unmanaged/Promise.h
	Stackable/Unmanaged/PromiseBase.h
	Stackable/Unmanaged/PromiseBaseConcept.h
	Stackable/Unmanaged/PromiseFinalAwaiter.h
	Stackable/Unmanaged/Task.h
	# Stackable/Unmanaged/Eager/
	Stackable/Unmanaged/Eager/DefaultPromise.h
	Stackable/Unmanaged/Eager/DefaultTask.h
	Stackable/Unmanaged/Eager/Promise.h
	Stackable/Unmanaged/Eager/PromiseBase.h
	# Stackable/Unmanaged/Lazy/
	Stackable/Unmanaged/Lazy/DefaultPromise.h
	Stackable/Unmanaged/Lazy/DefaultTask.h
	Stackable/Unmanaged/Lazy/Promise.h
	Stackable/Unmanaged/Lazy/PromiseBase.h
)
set(
	PLATFORM_DEPENDENT_INCLUDES
)

# Set the source files
set(
	SOURCES
	# Stackable/
	Stackable/Promise.cpp
	# Stackable/Managed/
	Stackable/Managed/PromiseBase.cpp
	Stackable/Managed/PromiseFinalAwaiter.cpp
	# Stackable/Managed/Eager/
	Stackable/Managed/Eager/PromiseBase.cpp
	# Stackable/Managed/Lazy/
	Stackable/Managed/Lazy/PromiseBase.cpp
	# Stackable/Unmanaged/
	Stackable/Unmanaged/PromiseBase.cpp
	Stackable/Unmanaged/PromiseFinalAwaiter.cpp
	# Stackable/Unmanaged/Eager/
	Stackable/Unmanaged/Eager/DefaultPromise.cpp
	Stackable/Unmanaged/Eager/PromiseBase.cpp
	# Stackable/Unmanaged/Lazy/
	Stackable/Unmanaged/Lazy/DefaultPromise.cpp
	Stackable/Unmanaged/Lazy/PromiseBase.cpp
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