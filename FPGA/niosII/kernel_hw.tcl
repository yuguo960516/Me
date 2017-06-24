# _hw.tcl file for kernel
package require -exact qsys 14.0

# module properties
set_module_property NAME {kernel_export}
set_module_property DISPLAY_NAME {kernel_export_display}

# default module properties
set_module_property VERSION {1.0}
set_module_property GROUP {default group}
set_module_property DESCRIPTION {default description}
set_module_property AUTHOR {author}

set_module_property COMPOSITION_CALLBACK compose
set_module_property opaque_address_map false

proc compose { } {
    # Instances and instance parameters
    # (disabled instances are intentionally culled)
    add_instance clk clock_source 16.1
    set_instance_parameter_value clk {clockFrequency} {100000000.0}
    set_instance_parameter_value clk {clockFrequencyKnown} {1}
    set_instance_parameter_value clk {resetSynchronousEdges} {NONE}

    add_instance jtag_uart altera_avalon_jtag_uart 16.1
    set_instance_parameter_value jtag_uart {allowMultipleConnections} {0}
    set_instance_parameter_value jtag_uart {hubInstanceID} {0}
    set_instance_parameter_value jtag_uart {readBufferDepth} {64}
    set_instance_parameter_value jtag_uart {readIRQThreshold} {8}
    set_instance_parameter_value jtag_uart {simInputCharacterStream} {}
    set_instance_parameter_value jtag_uart {simInteractiveOptions} {NO_INTERACTIVE_WINDOWS}
    set_instance_parameter_value jtag_uart {useRegistersForReadBuffer} {0}
    set_instance_parameter_value jtag_uart {useRegistersForWriteBuffer} {0}
    set_instance_parameter_value jtag_uart {useRelativePathForSimFile} {0}
    set_instance_parameter_value jtag_uart {writeBufferDepth} {64}
    set_instance_parameter_value jtag_uart {writeIRQThreshold} {8}

    add_instance nios2 altera_nios2_gen2 16.1
    set_instance_parameter_value nios2 {tmr_enabled} {0}
    set_instance_parameter_value nios2 {setting_disable_tmr_inj} {0}
    set_instance_parameter_value nios2 {setting_showUnpublishedSettings} {0}
    set_instance_parameter_value nios2 {setting_showInternalSettings} {0}
    set_instance_parameter_value nios2 {setting_preciseIllegalMemAccessException} {0}
    set_instance_parameter_value nios2 {setting_exportPCB} {0}
    set_instance_parameter_value nios2 {setting_exportdebuginfo} {0}
    set_instance_parameter_value nios2 {setting_clearXBitsLDNonBypass} {1}
    set_instance_parameter_value nios2 {setting_bigEndian} {0}
    set_instance_parameter_value nios2 {setting_export_large_RAMs} {0}
    set_instance_parameter_value nios2 {setting_asic_enabled} {0}
    set_instance_parameter_value nios2 {register_file_por} {0}
    set_instance_parameter_value nios2 {setting_asic_synopsys_translate_on_off} {0}
    set_instance_parameter_value nios2 {setting_asic_third_party_synthesis} {0}
    set_instance_parameter_value nios2 {setting_asic_add_scan_mode_input} {0}
    set_instance_parameter_value nios2 {setting_oci_version} {1}
    set_instance_parameter_value nios2 {setting_fast_register_read} {0}
    set_instance_parameter_value nios2 {setting_exportHostDebugPort} {0}
    set_instance_parameter_value nios2 {setting_oci_export_jtag_signals} {0}
    set_instance_parameter_value nios2 {setting_avalonDebugPortPresent} {0}
    set_instance_parameter_value nios2 {setting_alwaysEncrypt} {1}
    set_instance_parameter_value nios2 {io_regionbase} {0}
    set_instance_parameter_value nios2 {io_regionsize} {0}
    set_instance_parameter_value nios2 {setting_support31bitdcachebypass} {1}
    set_instance_parameter_value nios2 {setting_activateTrace} {0}
    set_instance_parameter_value nios2 {setting_allow_break_inst} {0}
    set_instance_parameter_value nios2 {setting_activateTestEndChecker} {0}
    set_instance_parameter_value nios2 {setting_ecc_sim_test_ports} {0}
    set_instance_parameter_value nios2 {setting_disableocitrace} {0}
    set_instance_parameter_value nios2 {setting_activateMonitors} {1}
    set_instance_parameter_value nios2 {setting_HDLSimCachesCleared} {1}
    set_instance_parameter_value nios2 {setting_HBreakTest} {0}
    set_instance_parameter_value nios2 {setting_breakslaveoveride} {0}
    set_instance_parameter_value nios2 {mpu_useLimit} {0}
    set_instance_parameter_value nios2 {mpu_enabled} {0}
    set_instance_parameter_value nios2 {mmu_enabled} {0}
    set_instance_parameter_value nios2 {mmu_autoAssignTlbPtrSz} {1}
    set_instance_parameter_value nios2 {cpuReset} {0}
    set_instance_parameter_value nios2 {resetrequest_enabled} {1}
    set_instance_parameter_value nios2 {setting_removeRAMinit} {0}
    set_instance_parameter_value nios2 {setting_tmr_output_disable} {0}
    set_instance_parameter_value nios2 {setting_shadowRegisterSets} {0}
    set_instance_parameter_value nios2 {mpu_numOfInstRegion} {8}
    set_instance_parameter_value nios2 {mpu_numOfDataRegion} {8}
    set_instance_parameter_value nios2 {mmu_TLBMissExcOffset} {0}
    set_instance_parameter_value nios2 {resetOffset} {0}
    set_instance_parameter_value nios2 {exceptionOffset} {32}
    set_instance_parameter_value nios2 {cpuID} {0}
    set_instance_parameter_value nios2 {breakOffset} {32}
    set_instance_parameter_value nios2 {userDefinedSettings} {}
    set_instance_parameter_value nios2 {tracefilename} {}
    set_instance_parameter_value nios2 {resetSlave} {sdram.s1}
    set_instance_parameter_value nios2 {mmu_TLBMissExcSlave} {None}
    set_instance_parameter_value nios2 {exceptionSlave} {sdram.s1}
    set_instance_parameter_value nios2 {breakSlave} {None}
    set_instance_parameter_value nios2 {setting_interruptControllerType} {Internal}
    set_instance_parameter_value nios2 {setting_branchpredictiontype} {Dynamic}
    set_instance_parameter_value nios2 {setting_bhtPtrSz} {8}
    set_instance_parameter_value nios2 {cpuArchRev} {1}
    set_instance_parameter_value nios2 {mul_shift_choice} {0}
    set_instance_parameter_value nios2 {mul_32_impl} {2}
    set_instance_parameter_value nios2 {mul_64_impl} {0}
    set_instance_parameter_value nios2 {shift_rot_impl} {1}
    set_instance_parameter_value nios2 {dividerType} {no_div}
    set_instance_parameter_value nios2 {mpu_minInstRegionSize} {12}
    set_instance_parameter_value nios2 {mpu_minDataRegionSize} {12}
    set_instance_parameter_value nios2 {mmu_uitlbNumEntries} {4}
    set_instance_parameter_value nios2 {mmu_udtlbNumEntries} {6}
    set_instance_parameter_value nios2 {mmu_tlbPtrSz} {7}
    set_instance_parameter_value nios2 {mmu_tlbNumWays} {16}
    set_instance_parameter_value nios2 {mmu_processIDNumBits} {8}
    set_instance_parameter_value nios2 {impl} {Fast}
    set_instance_parameter_value nios2 {icache_size} {4096}
    set_instance_parameter_value nios2 {fa_cache_line} {2}
    set_instance_parameter_value nios2 {fa_cache_linesize} {0}
    set_instance_parameter_value nios2 {icache_tagramBlockType} {Automatic}
    set_instance_parameter_value nios2 {icache_ramBlockType} {Automatic}
    set_instance_parameter_value nios2 {icache_numTCIM} {0}
    set_instance_parameter_value nios2 {icache_burstType} {None}
    set_instance_parameter_value nios2 {dcache_bursts} {false}
    set_instance_parameter_value nios2 {dcache_victim_buf_impl} {ram}
    set_instance_parameter_value nios2 {dcache_size} {2048}
    set_instance_parameter_value nios2 {dcache_tagramBlockType} {Automatic}
    set_instance_parameter_value nios2 {dcache_ramBlockType} {Automatic}
    set_instance_parameter_value nios2 {dcache_numTCDM} {0}
    set_instance_parameter_value nios2 {setting_exportvectors} {0}
    set_instance_parameter_value nios2 {setting_usedesignware} {0}
    set_instance_parameter_value nios2 {setting_ecc_present} {0}
    set_instance_parameter_value nios2 {setting_ic_ecc_present} {1}
    set_instance_parameter_value nios2 {setting_rf_ecc_present} {1}
    set_instance_parameter_value nios2 {setting_mmu_ecc_present} {1}
    set_instance_parameter_value nios2 {setting_dc_ecc_present} {1}
    set_instance_parameter_value nios2 {setting_itcm_ecc_present} {1}
    set_instance_parameter_value nios2 {setting_dtcm_ecc_present} {1}
    set_instance_parameter_value nios2 {regfile_ramBlockType} {Automatic}
    set_instance_parameter_value nios2 {ocimem_ramBlockType} {Automatic}
    set_instance_parameter_value nios2 {ocimem_ramInit} {0}
    set_instance_parameter_value nios2 {mmu_ramBlockType} {Automatic}
    set_instance_parameter_value nios2 {bht_ramBlockType} {Automatic}
    set_instance_parameter_value nios2 {cdx_enabled} {0}
    set_instance_parameter_value nios2 {mpx_enabled} {0}
    set_instance_parameter_value nios2 {debug_enabled} {1}
    set_instance_parameter_value nios2 {debug_triggerArming} {1}
    set_instance_parameter_value nios2 {debug_debugReqSignals} {0}
    set_instance_parameter_value nios2 {debug_assignJtagInstanceID} {0}
    set_instance_parameter_value nios2 {debug_jtagInstanceID} {0}
    set_instance_parameter_value nios2 {debug_OCIOnchipTrace} {_128}
    set_instance_parameter_value nios2 {debug_hwbreakpoint} {0}
    set_instance_parameter_value nios2 {debug_datatrigger} {0}
    set_instance_parameter_value nios2 {debug_traceType} {none}
    set_instance_parameter_value nios2 {debug_traceStorage} {onchip_trace}
    set_instance_parameter_value nios2 {master_addr_map} {0}
    set_instance_parameter_value nios2 {instruction_master_paddr_base} {0}
    set_instance_parameter_value nios2 {instruction_master_paddr_size} {0.0}
    set_instance_parameter_value nios2 {flash_instruction_master_paddr_base} {0}
    set_instance_parameter_value nios2 {flash_instruction_master_paddr_size} {0.0}
    set_instance_parameter_value nios2 {data_master_paddr_base} {0}
    set_instance_parameter_value nios2 {data_master_paddr_size} {0.0}
    set_instance_parameter_value nios2 {tightly_coupled_instruction_master_0_paddr_base} {0}
    set_instance_parameter_value nios2 {tightly_coupled_instruction_master_0_paddr_size} {0.0}
    set_instance_parameter_value nios2 {tightly_coupled_instruction_master_1_paddr_base} {0}
    set_instance_parameter_value nios2 {tightly_coupled_instruction_master_1_paddr_size} {0.0}
    set_instance_parameter_value nios2 {tightly_coupled_instruction_master_2_paddr_base} {0}
    set_instance_parameter_value nios2 {tightly_coupled_instruction_master_2_paddr_size} {0.0}
    set_instance_parameter_value nios2 {tightly_coupled_instruction_master_3_paddr_base} {0}
    set_instance_parameter_value nios2 {tightly_coupled_instruction_master_3_paddr_size} {0.0}
    set_instance_parameter_value nios2 {tightly_coupled_data_master_0_paddr_base} {0}
    set_instance_parameter_value nios2 {tightly_coupled_data_master_0_paddr_size} {0.0}
    set_instance_parameter_value nios2 {tightly_coupled_data_master_1_paddr_base} {0}
    set_instance_parameter_value nios2 {tightly_coupled_data_master_1_paddr_size} {0.0}
    set_instance_parameter_value nios2 {tightly_coupled_data_master_2_paddr_base} {0}
    set_instance_parameter_value nios2 {tightly_coupled_data_master_2_paddr_size} {0.0}
    set_instance_parameter_value nios2 {tightly_coupled_data_master_3_paddr_base} {0}
    set_instance_parameter_value nios2 {tightly_coupled_data_master_3_paddr_size} {0.0}
    set_instance_parameter_value nios2 {instruction_master_high_performance_paddr_base} {0}
    set_instance_parameter_value nios2 {instruction_master_high_performance_paddr_size} {0.0}
    set_instance_parameter_value nios2 {data_master_high_performance_paddr_base} {0}
    set_instance_parameter_value nios2 {data_master_high_performance_paddr_size} {0.0}

    add_instance sdram altera_avalon_new_sdram_controller 16.1
    set_instance_parameter_value sdram {TAC} {5.4}
    set_instance_parameter_value sdram {TRCD} {20.0}
    set_instance_parameter_value sdram {TRFC} {70.0}
    set_instance_parameter_value sdram {TRP} {20.0}
    set_instance_parameter_value sdram {TWR} {20.0}
    set_instance_parameter_value sdram {casLatency} {3}
    set_instance_parameter_value sdram {columnWidth} {9}
    set_instance_parameter_value sdram {dataWidth} {16}
    set_instance_parameter_value sdram {generateSimulationModel} {0}
    set_instance_parameter_value sdram {initRefreshCommands} {8}
    set_instance_parameter_value sdram {model} {single_Micron_MT48LC4M32B2_7_chip}
    set_instance_parameter_value sdram {numberOfBanks} {4}
    set_instance_parameter_value sdram {numberOfChipSelects} {1}
    set_instance_parameter_value sdram {pinsSharedViaTriState} {0}
    set_instance_parameter_value sdram {powerUpDelay} {200.0}
    set_instance_parameter_value sdram {refreshPeriod} {7.8125}
    set_instance_parameter_value sdram {rowWidth} {13}
    set_instance_parameter_value sdram {masteredTristateBridgeSlave} {0}
    set_instance_parameter_value sdram {TMRD} {3.0}
    set_instance_parameter_value sdram {initNOPDelay} {0.0}
    set_instance_parameter_value sdram {registerDataIn} {1}

    add_instance sysid altera_avalon_sysid_qsys 16.1
    set_instance_parameter_value sysid {id} {0}

    # connections and connection parameters
    add_connection nios2.data_master jtag_uart.avalon_jtag_slave avalon
    set_connection_parameter_value nios2.data_master/jtag_uart.avalon_jtag_slave arbitrationPriority {1}
    set_connection_parameter_value nios2.data_master/jtag_uart.avalon_jtag_slave baseAddress {0x04001000}
    set_connection_parameter_value nios2.data_master/jtag_uart.avalon_jtag_slave defaultConnection {0}

    add_connection nios2.data_master sysid.control_slave avalon
    set_connection_parameter_value nios2.data_master/sysid.control_slave arbitrationPriority {1}
    set_connection_parameter_value nios2.data_master/sysid.control_slave baseAddress {0x04001008}
    set_connection_parameter_value nios2.data_master/sysid.control_slave defaultConnection {0}

    add_connection nios2.data_master nios2.debug_mem_slave avalon
    set_connection_parameter_value nios2.data_master/nios2.debug_mem_slave arbitrationPriority {1}
    set_connection_parameter_value nios2.data_master/nios2.debug_mem_slave baseAddress {0x04000800}
    set_connection_parameter_value nios2.data_master/nios2.debug_mem_slave defaultConnection {0}

    add_connection nios2.data_master sdram.s1 avalon
    set_connection_parameter_value nios2.data_master/sdram.s1 arbitrationPriority {1}
    set_connection_parameter_value nios2.data_master/sdram.s1 baseAddress {0x02000000}
    set_connection_parameter_value nios2.data_master/sdram.s1 defaultConnection {0}

    add_connection nios2.instruction_master nios2.debug_mem_slave avalon
    set_connection_parameter_value nios2.instruction_master/nios2.debug_mem_slave arbitrationPriority {1}
    set_connection_parameter_value nios2.instruction_master/nios2.debug_mem_slave baseAddress {0x04000800}
    set_connection_parameter_value nios2.instruction_master/nios2.debug_mem_slave defaultConnection {0}

    add_connection nios2.instruction_master sdram.s1 avalon
    set_connection_parameter_value nios2.instruction_master/sdram.s1 arbitrationPriority {1}
    set_connection_parameter_value nios2.instruction_master/sdram.s1 baseAddress {0x02000000}
    set_connection_parameter_value nios2.instruction_master/sdram.s1 defaultConnection {0}

    add_connection clk.clk nios2.clk clock

    add_connection clk.clk sdram.clk clock

    add_connection clk.clk sysid.clk clock

    add_connection clk.clk jtag_uart.clk clock

    add_connection nios2.irq jtag_uart.irq interrupt
    set_connection_parameter_value nios2.irq/jtag_uart.irq irqNumber {0}

    add_connection clk.clk_reset nios2.reset reset

    add_connection clk.clk_reset sdram.reset reset

    add_connection clk.clk_reset sysid.reset reset

    add_connection clk.clk_reset jtag_uart.reset reset

    add_connection nios2.debug_reset_request nios2.reset reset

    add_connection nios2.debug_reset_request sdram.reset reset

    add_connection nios2.debug_reset_request sysid.reset reset

    add_connection nios2.debug_reset_request jtag_uart.reset reset

    # exported interfaces
    add_interface clk clock sink
    set_interface_property clk EXPORT_OF clk.clk_in
    add_interface reset reset sink
    set_interface_property reset EXPORT_OF clk.clk_in_reset
    add_interface sdram conduit end
    set_interface_property sdram EXPORT_OF sdram.wire

    # interconnect requirements
    set_interconnect_requirement {$system} {qsys_mm.clockCrossingAdapter} {HANDSHAKE}
    set_interconnect_requirement {$system} {qsys_mm.maxAdditionalLatency} {1}
    set_interconnect_requirement {$system} {qsys_mm.enableEccProtection} {FALSE}
    set_interconnect_requirement {$system} {qsys_mm.insertDefaultSlave} {FALSE}
}
