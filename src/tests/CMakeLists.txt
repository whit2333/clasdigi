set(test_names 
   clasdigi-test1 
   clasdigi-test2 
   tdc_test1 
   tdc_test2
   crate_test
   crate_test2
   flash_adc_test1
   sigs_test1
   trigger_test1
   catch_test
   create_test_hits
   template_modules
   lund_test
   geo_test1
   field_test
   field_test_solenoid
   field_test_toroid
   )

foreach(exename ${test_names})
   add_executable(${exename} ${exename}.cxx)
   target_link_libraries(${exename} ClasDAQ ClasHits ClasSigs ClasSim ClasGeo ClasMag)
   install(TARGETS ${exename}
      # IMPORTANT: Add the bar executable to the "export-set"
      RUNTIME DESTINATION "${CMAKE_BINARY_DIR}" COMPONENT bin)
endforeach()


#target_link_libraries(${exename} ClasDAQ ClasHits)
