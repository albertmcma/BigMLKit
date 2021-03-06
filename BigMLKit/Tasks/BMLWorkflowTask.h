// Copyright 2014-2015 BigML
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may
// not use this file except in compliance with the License. You may obtain
// a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations
// under the License.

#import <Foundation/Foundation.h>
#import "BMLWorkflow.h"

@class BMLWorkflowTaskContext;
@class BMLWorkflowTaskConfiguration;
@class BMLWorkflowConfigurator;

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
/**
 *  BMLWorkflowTask is the simplest form of BMLWorkflow, i.e., a workflow comprised of 
 *  one single step (e.g., create data source, create data set, etc.). This can be used
 *  as the basic building block for more complex workflows, such as BMLWorkfloTaskSequence.
 */
@interface BMLWorkflowTask : BMLWorkflow

/**
 *  A configuration object storing the current configuration for this task.
 */
@property (nonatomic, strong) BMLWorkflowTaskConfiguration* configuration;

/**
 *  Convenience constructor. It acts as a factory method, in that it takes a string and creates
 *  a BMLWorkflowTask. The string is used to idnetify the concrete class to instantiate, e.g., 
 *  BMLWorkflowTaskCreateDataset from a CreateDataset parameter. The class must be defined,
 *  otherwise the program will crash.
 *  The task is furthermore initialized so to use the given configurator object.
 *
 *  @param step         a string representing the task name.
 *  @param configurator the configurator object to use.
 *
 *  @return the initialized instance.
 */
+ (BMLWorkflowTask*)newTaskForStep:(NSString*)step configurator:(BMLWorkflowConfigurator*)configurator;

@end

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
/**
 *  This class is an "empty" BMLWorkflowTask that can be used as a placeholder.
 */
@interface BMLWorkflowNoOpTask : BMLWorkflowTask
@end
