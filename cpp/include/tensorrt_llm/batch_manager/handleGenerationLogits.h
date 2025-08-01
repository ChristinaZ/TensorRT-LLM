/*
 * SPDX-FileCopyrightText: Copyright (c) 2022-2024 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "common.h"
#include "tensorrt_llm/common/algorithm.h"
#include "tensorrt_llm/common/optionalRef.h"
#include "tensorrt_llm/runtime/modelConfig.h"

namespace tensorrt_llm::runtime
{
class BufferManager;
} // namespace tensorrt_llm::runtime

namespace tensorrt_llm::batch_manager
{

class DecoderInputBuffers;
class RuntimeBuffers;
class MedusaBuffers;

class HandleGenerationLogits : Algorithm
{
public:
    template <typename T>
    using OptionalRef = tensorrt_llm::common::OptionalRef<T>;

    constexpr static auto name{"HandleGenerationLogits"};

    HandleGenerationLogits() = default;

    void operator()(DecoderInputBuffers& inputBuffers, RequestVector const& generationRequests,
        runtime::ITensor::SharedPtr const& logits, runtime::SizeType32 logitsIndex,
        runtime::ModelConfig const& modelConfig, runtime::BufferManager const& manager,
        OptionalRef<RuntimeBuffers> genRuntimeBuffers, OptionalRef<MedusaBuffers> medusaBuffers) const;
};

} // namespace tensorrt_llm::batch_manager
