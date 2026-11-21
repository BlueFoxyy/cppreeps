set(SOURCES
	loop.cpp
)

target_sources(${TARGET_NAME} PRIVATE ${SOURCES})
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(${TARGET_NAME} PRIVATE screepsxx)
target_compile_options(${TARGET_NAME}
	PRIVATE
		-O3
		-Werror
		-Wall
		-pedantic
)
target_link_options(${TARGET_NAME}
	PRIVATE
		--no-entry
		-sWASM_ASYNC_COMPILATION=1
		-sENVIRONMENT=shell
		-sSTRICT
		--pre-js ${CMAKE_SOURCE_DIR}/js/pre_js.js
		--post-js ${CMAKE_SOURCE_DIR}/js/post_js.js
		-lembind
)
