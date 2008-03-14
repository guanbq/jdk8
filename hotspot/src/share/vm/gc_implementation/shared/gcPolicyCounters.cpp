/*
 * Copyright 2002-2004 Sun Microsystems, Inc.  All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa Clara,
 * CA 95054 USA or visit www.sun.com if you need additional information or
 * have any questions.
 *
 */

# include "incls/_precompiled.incl"
# include "incls/_gcPolicyCounters.cpp.incl"

GCPolicyCounters::GCPolicyCounters(const char* name, int collectors,
                                   int generations) {

  if (UsePerfData) {
    EXCEPTION_MARK;
    ResourceMark rm;

    _name_space = "policy";

    char* cname = PerfDataManager::counter_name(_name_space, "name");
    PerfDataManager::create_string_constant(SUN_GC, cname, name, CHECK);

    cname = PerfDataManager::counter_name(_name_space, "collectors");
    PerfDataManager::create_constant(SUN_GC, cname,  PerfData::U_None,
                                     collectors, CHECK);

    cname = PerfDataManager::counter_name(_name_space, "generations");
    PerfDataManager::create_constant(SUN_GC, cname,  PerfData::U_None,
                                     generations, CHECK);

    cname = PerfDataManager::counter_name(_name_space, "maxTenuringThreshold");
    PerfDataManager::create_constant(SUN_GC, cname, PerfData::U_None,
                                     MaxTenuringThreshold, CHECK);

    cname = PerfDataManager::counter_name(_name_space, "tenuringThreshold");
    _tenuring_threshold =
        PerfDataManager::create_variable(SUN_GC, cname, PerfData::U_None,
                                         MaxTenuringThreshold, CHECK);

    cname = PerfDataManager::counter_name(_name_space, "desiredSurvivorSize");
    _desired_survivor_size =
        PerfDataManager::create_variable(SUN_GC, cname, PerfData::U_Bytes,
                                         CHECK);
  }
}